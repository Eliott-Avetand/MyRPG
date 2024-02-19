/*
** EPITECH PROJECT, 2020
** create_stats.c
** File description:
** Functions that deal with the stats
*/
#include "rpg.h"

sprite_t *create_stats_sprite(void)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {300, 0, 150, 150};

    if (!sprite)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(INVENTORY_SPT, NULL);
    if (!sprite->sprite || !sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_scale(sprite->sprite, (sfVector2f){2.5, 2.5});
    sfSprite_setPosition(sprite->sprite, (sfVector2f){700, 910});
    return sprite;
}

sprite_t *create_front_sprite(void)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 256, 64, 64};

    if (!sprite)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(PLAYER_SPT, NULL);
    if (!sprite->sprite || !sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_scale(sprite->sprite, (sfVector2f){2, 2});
    return sprite;
}

int create_stats_texts(stats_t *stats)
{
    char *text_settings[11] = {STATISTICS, LEVEL, ATK, DEFENSE, HEALTH, MONEY,
    LEVEL_VALUE, ATK_VALUE, DEFENSE_VALUE, HEALTH_VALUE, MONEY_VALUE};

    for (int i = 0; i < 11; i++) {
        stats->text[i] = create_text(stats->font, text_settings[i]);
        if (!stats->text[i])
            return -1;
        stats->text[i + 1] = NULL;
    }
    return 0;
}

stats_t *create_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    if (!stats)
        return NULL;
    stats->font = sfFont_createFromFile(FONT);
    stats->player = create_front_sprite();
    stats->sprite = create_stats_sprite();
    if (!stats->font || !stats->player || !stats->sprite)
        return NULL;
    stats->level = 1;
    stats->damage = 6;
    stats->defense = 5;
    stats->health = 6;
    stats->money = 0;
    stats->xp = 0;
    if (create_stats_texts(stats) == -1)
        return NULL;
    return stats;
}