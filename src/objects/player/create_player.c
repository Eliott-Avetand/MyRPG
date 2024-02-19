/*
** EPITECH PROJECT, 2021
** create_player.c
** File description:
** create the player
*/

#include "rpg.h"

direction_t *create_player_movement(void)
{
    direction_t *direction = malloc(sizeof(direction_t));

    if (!direction)
        return NULL;
    direction->clock = sfClock_create();
    direction->attack_clk = sfClock_create();
    direction->attack_status = IS_ATTACKING;
    direction->direction = BACK;
    direction->is_moving = IDLE;
    direction->floor = 0;
    return direction;
}

sprite_t *create_player_sprite(player_t *player)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, (int)player->movement->direction, 64, 64};

    if (!sprite)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(PLAYER_SPT, NULL);
    if (!sprite->sprite || !sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_setPosition(sprite->sprite, (sfVector2f){416, 416});
    return sprite;
}

int create_player_hitbox(player_t *player)
{
    player->attack_box = sfRectangleShape_create();
    player->hitbox = sfRectangleShape_create();
    if (!player->hitbox || !player->attack_box)
        return EXIT_ERROR;
    sfRectangleShape_setSize(player->attack_box, (Vec2f){32, 32});
    sfRectangleShape_setPosition(player->attack_box, (Vec2f){416, 416});
    sfRectangleShape_setFillColor(player->attack_box, sfYellow);
    sfRectangleShape_setSize(player->hitbox, (Vec2f){32, 32});
    sfRectangleShape_setPosition(player->hitbox, (Vec2f){416, 416});
    return 0;
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->movement = create_player_movement();
    player->inventory = create_inventory();
    player->player_sounds = create_player_sounds();
    player->stats = create_stats();
    player->sprite = create_player_sprite(player);
    player->key = create_enter_key();
    if (!player->key)
        return NULL;
    player->player_status = ALIVE;
    if (!player->inventory || !player->sprite || !player->player_sounds ||
    !player->movement || !player->stats || create_player_hitbox(player) != 0)
        return NULL;
    return player;
}