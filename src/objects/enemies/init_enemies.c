/*
** EPITECH PROJECT, 2020
** init_ennemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

int create_enemy_hitbox(enemies_t *enemy)
{
    enemy->attack_box = sfRectangleShape_create();
    enemy->hitbox = sfRectangleShape_create();
    if (!enemy->attack_box || !enemy->hitbox)
        return EXIT_ERROR;
    sfRectangleShape_setFillColor(enemy->hitbox, sfBlue);
    sfRectangleShape_setSize(enemy->hitbox, (Vec2f){32, 32});
    sfRectangleShape_setPosition(enemy->hitbox, (Vec2f){416, 416});
    sfRectangleShape_setFillColor(enemy->attack_box, sfYellow);
    sfRectangleShape_setSize(enemy->attack_box, (Vec2f){32, 32});
    sfRectangleShape_setPosition(enemy->attack_box, (Vec2f){416, 416});
    return 0;
}

enemy_direction_t *init_enemy_direction(void)
{
    enemy_direction_t *direction = malloc(sizeof(direction_t));

    if (!direction)
        return NULL;
    direction->e_move = malloc(sizeof(enemy_movement_t));
    if (!direction->e_move)
        return NULL;
    direction->e_move->movement = sfClock_create();
    direction->clock = sfClock_create();
    direction->attack_clock = sfClock_create();
    direction->e_move->r_milisec = random_float(5000, 7000);
    direction->e_move->move_pos = (sfVector2f){0, 0};
    direction->e_move->nbr_move = 0;
    direction->e_direction = E_LEFT;
    direction->b_direction = B_BACKWARD;
    direction->enemy_status = E_IDLE;
    direction->attack_status = IS_ATTACKING;
    return direction;
}

sprite_t *create_enemy_sprite(sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, E_LEFT, 65.75, 75};

    if (!sprite)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(SKELETON_SPT, NULL);
    if (!sprite->sprite || !sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_setPosition(sprite->sprite, pos);
    sfSprite_setScale(sprite->sprite, (sfVector2f){0.75, 0.75});
    return sprite;
}

enemies_t *create_enemy(sfVector2f pos)
{
    enemies_t *enemy = malloc(sizeof(enemies_t));

    if (!enemy)
        return NULL;
    enemy->direction = init_enemy_direction();
    enemy->sprite = create_enemy_sprite(pos);
    enemy->dead_sounds = create_sounds(ENEMY_DEATH);
    if (!enemy->sprite || create_enemy_hitbox(enemy) != 0)
        return NULL;
    enemy->time_death = sfClock_create();
    enemy->enemy_status = ALIVE;
    enemy->spawn_pos = pos;
    enemy->death = 0;
    enemy->have_attack = 0;
    enemy->defense = 5;
    enemy->damage = 6;
    enemy->max_health = 5;
    enemy->health = enemy->max_health;
    return enemy;
}