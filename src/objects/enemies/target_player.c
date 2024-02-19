/*
** EPITECH PROJECT, 2020
** clean_ennemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

void update_player_pos(player_t *player)
{
    sfVector2f true_pos = sfSprite_getPosition(player->sprite->sprite);

    player->player_pos[0] = (Vec2f){true_pos.x - 16, true_pos.y};
    player->player_pos[1] = (Vec2f){true_pos.x - 16, true_pos.y + 32};
    player->player_pos[2] = (Vec2f){true_pos.x, true_pos.y - 16};
    player->player_pos[3] = (Vec2f){true_pos.x + 32, true_pos.y - 16};
}

void update_enemy_hitbox(enemies_t *enemy)
{
    sfVector2f e_pos = sfSprite_getPosition(enemy->sprite->sprite);

    e_pos.x += 16;
    e_pos.y += 16;
    sfRectangleShape_setPosition(enemy->hitbox, e_pos);
}

sfVector2f get_few_distance(player_t *player, enemies_t *enemy)
{
    sfVector2f save = player->player_pos[0];
    sfVector2f e_pos = sfSprite_getPosition(enemy->sprite->sprite);
    sfVector2f distance = {abs((int)(save.x - e_pos.x)), abs((int)(save.y - e_pos.y))};

    for (int i = 1; i < 4; i++) {
        if (distance.x > abs((int)(e_pos.x - player->player_pos[i].x)) &&
        distance.y > abs((int)(e_pos.y - player->player_pos[i].y))) {
            save = player->player_pos[i];
            distance = (Vec2f){abs((int)(save.x - e_pos.x)), abs((int)(save.y - e_pos.y))};
        }
    }
    return save;
}

void target_player(player_t *player, enemies_t *enemy, map_t *map)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->e_move->movement);
    sfFloatRect e_bounds = update_bound_enemy(enemy);
    sfFloatRect p_bounds = sfSprite_getGlobalBounds(player->sprite->sprite);
    sfVector2f e_pos = sfSprite_getPosition(enemy->sprite->sprite);
    sfVector2f offset;

    anim_enemies(enemy);
    if (sfTime_asMilliseconds(time) > 50) {
        offset = go_to_player(player, enemy, e_pos);
        if (is_colliding(getBounds(enemy->sprite->sprite), offset, map) == 1)
            return;
        sfSprite_move(enemy->sprite->sprite, offset);
        sfClock_restart(enemy->direction->e_move->movement);
        enemy->direction->e_move->nbr_move =
        (enemy->direction->e_move->nbr_move == 1) ? 0 : 1;
        if (sfFloatRect_intersects(&p_bounds, &e_bounds, NULL) == sfFalse) {
            enemy->direction->e_move->r_milisec = random_float(5000, 7000);
            enemy->direction->enemy_status = E_IDLE;
        }
    }
}