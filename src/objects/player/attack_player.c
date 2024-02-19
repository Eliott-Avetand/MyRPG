/*
** EPITECH PROJECT, 2021
** create_player.c
** File description:
** create the scene
*/

#include "rpg.h"

void check_player_stats(player_t *player)
{
    if (player->stats->xp >= (player->stats->level * 10)) {
        player->stats->xp = 0;
        player->stats->level++;
        player->stats->max_health += 2;
        player->stats->damage += 1;
        player->stats->defense += 1;
        player->stats->health = player->stats->max_health;
    }
}

void is_a_enemy(player_t *player, enemies_t *enemy)
{
    sfFloatRect attack_rect = rect_getGlobalBounds(player->attack_box);
    sfFloatRect enemy_rect = rect_getGlobalBounds(enemy->hitbox);
    sfIntRect text_rect = sfSprite_getTextureRect(enemy->sprite->sprite);

    if (sfFloatRect_intersects(&attack_rect, &enemy_rect, NULL) == sfTrue)
        enemy->health -= abs(player->stats->damage - enemy->defense);
    if (enemy->health <= 0 && enemy->enemy_status == ALIVE) {
        text_rect.left = 8 * 65.75;
        sfSprite_setTextureRect(enemy->sprite->sprite, text_rect);
        sfClock_restart(enemy->direction->clock);
        sfSound_play(enemy->dead_sounds->sound);
        enemy->enemy_status = BEFORE_DEAD;
        player->stats->xp += 10;
        player->stats->money += 25;
        check_player_stats(player);
    }
}

void is_a_boss(player_t *player, enemies_t *enemy)
{
    sfFloatRect attack_rect = sfRectangleShape_getGlobalBounds(player->attack_box);
    sfFloatRect enemy_rect = sfRectangleShape_getGlobalBounds(enemy->hitbox);
    sfIntRect text_rect = sfSprite_getTextureRect(enemy->sprite->sprite);

    if (sfFloatRect_intersects(&attack_rect, &enemy_rect, NULL) == sfTrue)
        enemy->health -= abs(player->stats->damage - enemy->defense);
    if (enemy->health <= 0 && enemy->enemy_status == ALIVE) {
        text_rect.left = 8 * 65.75;
        sfSprite_setTextureRect(enemy->sprite->sprite, text_rect);
        sfClock_restart(enemy->direction->clock);
        sfSound_play(enemy->dead_sounds->sound);
        enemy->enemy_status = DEAD;
        player->stats->xp += 10;
        player->stats->money += 25;
        check_player_stats(player);
    }
}

void update_attack_box(player_t *player, main_t *main)
{
    sfVector2f box_pos = sfSprite_getPosition(player->sprite->sprite);

    if (player->movement->direction == FORWARD)
        box_pos.y -= 32;
    if (player->movement->direction == BACK)
        box_pos.y += 32;
    if (player->movement->direction == LEFT)
        box_pos.x -= 32;
    if (player->movement->direction == RIGHT)
        box_pos.x += 32;
    sfRectangleShape_setPosition(player->attack_box, box_pos);
    if (main->actual_scene != ATLANTIS) {
        for (int i = 0; main->scenes[main->actual_scene]->
        enemies[i] != NULL; i++)
            is_a_enemy(player, main->scenes[main->actual_scene]->enemies[i]);
    } else
        is_a_boss(player, main->scenes[ATLANTIS]->enemies[0]);
}