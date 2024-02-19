/*
** EPITECH PROJECT, 2021
** create_collision_rect
** File description:
** create_collision_rect
*/

#include "rpg.h"

void destroy_all_rocks(scene_t *scene)
{
    for (int i = 0; scene->rocks[i] != NULL; i++) {
        sfSprite_destroy(scene->rocks[i]->sprite->sprite);
        sfTexture_destroy(scene->rocks[i]->sprite->texture);
        free(scene->rocks[i]->sprite);
        sfClock_destroy(scene->rocks[i]->clock);
        free(scene->rocks[i]);
    }
}

sprite_t *create_rocks_spt(void)
{
    sprite_t *spt = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 32, 128};

    if (!spt)
        return NULL;
    spt->sprite = sfSprite_create();
    spt->texture = sfTexture_createFromFile(ROCKS, NULL);
    if (!spt->sprite || !spt->texture)
        return NULL;
    sfSprite_setTexture(spt->sprite, spt->texture, sfTrue);
    sfSprite_setTextureRect(spt->sprite, rect);
    return spt;
}

rocks_t *create_rocks(void)
{
    rocks_t *rocks = malloc(sizeof(rocks_t));

    if (!rocks)
        return NULL;
    rocks->see_rocks = YES;
    rocks->clock = sfClock_create();
    rocks->sprite = create_rocks_spt();
    if (!rocks->sprite)
        return NULL;
    return rocks;
}

int create_other_rocks(main_t *main)
{
    main->scenes[CAVE]->rocks[0] = create_rocks();
    main->scenes[JUNGLE]->rocks[0] = create_rocks();
    if (!main->scenes[CAVE]->rocks[0] || !main->scenes[JUNGLE]->rocks[0])
        return EXIT_ERROR;
    sfSprite_setPosition(main->scenes[CAVE]->rocks[0]->sprite->sprite,
    (Vec2f){940, 950});
    sfSprite_setPosition(main->scenes[JUNGLE]->rocks[0]->sprite->sprite,
    (Vec2f){1700, 1500});
    main->scenes[CAVE]->rocks[1] = NULL;
    main->scenes[JUNGLE]->rocks[1] = NULL;
    return 0;
}

int create_all_rocks(main_t *main)
{
    sfVector2f hub_pos[4] = {{655, 775}, {1265, 775}, {655, 1360}, {1265, 1360}};

    for (int i = 0; i < 4; i++) {
        main->scenes[HUB]->rocks[i] = create_rocks();
        sfSprite_setPosition(main->scenes[HUB]->
        rocks[i]->sprite->sprite, hub_pos[i]);
        if (!main->scenes[HUB]->rocks[i])
            return EXIT_ERROR;
        if (i < 2)
            main->scenes[HUB]->rocks[i]->see_rocks = NO;
        main->scenes[HUB]->rocks[i + 1] = NULL;
    }
    if (create_other_rocks(main) == EXIT_ERROR)
        return EXIT_ERROR;
    return 0;
}