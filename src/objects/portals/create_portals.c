/*
** EPITECH PROJECT, 2020
** create_portals
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

sprite_t *create_portals_sprite(char *spt_path, sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 225, 540};

    if (!sprite)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(spt_path, NULL);
    if (!sprite->texture || !sprite->sprite)
        return NULL;
    setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_setOrigin(sprite->sprite, (sfVector2f){112.5, 270});
    sfSprite_setPosition(sprite->sprite, pos);
    sfSprite_setScale(sprite->sprite, (sfVector2f){0.30, 0.30});
    return sprite;
}

portals_t *init_portals(sfVector2f pos, sfVector2f tp, char *path,
void (*callbacks)(main_t *))
{
    portals_t *portal = malloc(sizeof(portals_t));

    if (!portal)
        return NULL;
    portal->clock = sfClock_create();
    portal->portal_sprite = create_portals_sprite(path, pos);
    portal->tp_position = tp;
    portal->see_portal = YES;
    portal->go_in = callbacks;
    return portal;
}

void init_portal_boss(portals_t *portal)
{
    sfIntRect rect = {0, 0, 320, 320};

    portal->see_portal = NO;
    sfSprite_setScale(portal->portal_sprite->sprite, (sfVector2f){1.6, 1.6});
    sfSprite_setTextureRect(portal->portal_sprite->sprite, rect);
}

void create_all_portals(main_t *main)
{
    sfVector2f pos_hub[3] = {{700, 910}, {1250, 910}, {900, 1400}};
    sfVector2f pos_tp[3] = {{1780, 700}, {96, 1760}, {300, 1700}};
    char *portal_path[3] = {ORANGE_PORTAL, GREEN_PORTAL, BOSS_PORTAL};
    void (*callbacks[3])(main_t *) = {go_ashland, go_jungle, go_boss};

    for (int i = 0; i < 3; i++) {
        main->scenes[HUB]->portals[i] = init_portals(pos_hub[i], pos_tp[i],
        portal_path[i], callbacks[i]);
        main->scenes[HUB]->portals[i + 1] = NULL;
    }
    init_portal_boss(main->scenes[HUB]->portals[2]);
    main->scenes[ASHLAND]->portals[0] = init_portals((sfVector2f){1860, 685},
    (sfVector2f){940, 820}, ORANGE_PORTAL, go_ashland);
    main->scenes[ASHLAND]->portals[1] = NULL;
    main->scenes[JUNGLE]->portals[0] = init_portals((sfVector2f){64, 1700},
    (sfVector2f){940, 820}, GREEN_PORTAL, go_jungle);
    main->scenes[JUNGLE]->portals[1] = NULL;
    main->scenes[ATLANTIS]->portals[0] = init_portals((sfVector2f){1860, 685},
    (sfVector2f){940, 820}, BOSS_PORTAL, go_boss);
    main->scenes[ATLANTIS]->portals[1] = NULL;
}