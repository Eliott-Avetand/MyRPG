/*
** EPITECH PROJECT, 2020
** attack_enemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

void enemy_attack_handler(enemies_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->attack_clock);

    if (sfTime_asMilliseconds(time) > 2000)
        enemy->direction->attack_status = IS_ATTACKING;
}

void anim_enemy_attack(enemies_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->clock);
    sfIntRect rect = sfSprite_getTextureRect(enemy->sprite->sprite);

    rect.top = enemy->direction->e_direction;
    enemy->direction->attack_status = WAIT;
    if (sfTime_asMilliseconds(time) > 100) {
        if (rect.left < 7 * 65.75)
            rect.left += 65.75;
        else {
            enemy->direction->enemy_status = E_IDLE;
            sfClock_restart(enemy->direction->attack_clock);
        }
        sfSprite_setTextureRect(enemy->sprite->sprite, rect);
        sfClock_restart(enemy->direction->clock);
    }
}

int is_a_player(player_t *player, enemies_t *enemy)
{
    sfFloatRect attack_rect = sfRectangleShape_getGlobalBounds(enemy->attack_box);
    sfFloatRect player_rect = sfRectangleShape_getGlobalBounds(player->hitbox);
    int have_player = 0;

    if (sfFloatRect_intersects(&attack_rect, &player_rect, NULL) == sfTrue) {
        sfSound_play(player->player_sounds->hit->sound);
        player->stats->health -= abs(enemy->damage - player->stats->defense);
        have_player++;
    }
    if (player->stats->health <= 0) {
        player->player_status = DEAD;
        update_death_menu(player);
    }
    return have_player;
}

void update_enemy_attack_box(enemies_t *enemy, main_t *main)
{
    sfVector2f box_pos = sfSprite_getPosition(enemy->sprite->sprite);

    box_pos.x += 16;
    box_pos.y += 16;
    if (enemy->direction->e_direction == E_FORWARD)
        box_pos.y -= 32;
    if (enemy->direction->e_direction == E_DOWN)
        box_pos.y += 32;
    if (enemy->direction->e_direction == E_LEFT)
        box_pos.x -= 32;
    if (enemy->direction->e_direction == E_RIGHT)
        box_pos.x += 32;
    sfRectangleShape_setPosition(enemy->attack_box, box_pos);
    if (enemy->direction->attack_status != WAIT) {
        if (is_a_player(main->player, enemy) == 1)
            enemy->direction->attack_status = WAIT;
    }
}

void is_near_the_player(player_t *player, enemies_t *enemy)
{
    sfFloatRect player_rect = sfRectangleShape_getGlobalBounds(player->hitbox);
    sfFloatRect enemy_rect = sfRectangleShape_getGlobalBounds(enemy->hitbox);

    if (sfFloatRect_intersects(&player_rect, &enemy_rect, NULL) == sfTrue &&
    enemy->direction->attack_status != WAIT) {
        sfClock_restart(enemy->direction->attack_clock);
        enemy->direction->enemy_status = E_ATTACK;
    }
}