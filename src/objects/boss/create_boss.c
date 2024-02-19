/*
** EPITECH PROJECT, 2020
** create_portals
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

int create_boss_hitbox(enemies_t *enemy)
{
    enemy->attack_box = sfRectangleShape_create();
    enemy->hitbox = sfRectangleShape_create();
    if (!enemy->attack_box || !enemy->hitbox)
        return EXIT_ERROR;
    sfRectangleShape_setFillColor(enemy->hitbox, sfBlue);
    sfRectangleShape_setSize(enemy->hitbox, (Vec2f){32, 64});
    sfRectangleShape_setPosition(enemy->hitbox, (Vec2f){416, 416});
    sfRectangleShape_setFillColor(enemy->attack_box, sfYellow);
    sfRectangleShape_setSize(enemy->attack_box, (Vec2f){32, 32});
    sfRectangleShape_setPosition(enemy->attack_box, (Vec2f){416, 416});
    return 0;
}

sprite_t *create_boss_sprite(sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, B_BACKWARD, 47, 87};

    if (!sprite)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(BOSS_SPT, NULL);
    if (!sprite->sprite || !sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_setPosition(sprite->sprite, pos);
    sfSprite_setScale(sprite->sprite, (sfVector2f){1.25, 1.25});
    return sprite;
}

enemy_direction_t *init_boss_direction(void)
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
    direction->b_direction = B_BACKWARD;
    direction->e_direction = E_LEFT;
    direction->enemy_status = E_IDLE;
    direction->attack_status = IS_ATTACKING;
    return direction;
}

enemies_t *create_boss(void)
{
    enemies_t *boss = malloc(sizeof(enemies_t));

    if (!boss)
        return NULL;
    boss->direction = init_boss_direction();
    boss->sprite = create_boss_sprite((Vec2f){700, 400});
    boss->dead_sounds = create_sounds(BOSS_DEATH);
    if (!boss->sprite || !boss->direction || !boss->dead_sounds ||
    create_boss_hitbox(boss) != 0)
        return NULL;
    boss->time_death = sfClock_create();
    boss->enemy_status = ALIVE;
    boss->spawn_pos = (Vec2f){700, 400};
    boss->death = 3;
    boss->have_attack = 0;
    boss->defense = 5;
    boss->damage = 3;
    boss->max_health = 35;
    boss->health = boss->max_health;
    return boss;
}