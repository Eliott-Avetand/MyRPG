/*
** EPITECH PROJECT, 2020
** create_portals
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

void anim_portals(portals_t *portal, int max_left, int add_left)
{
    sfTime time = sfClock_getElapsedTime(portal->clock);
    sfIntRect rect = sfSprite_getTextureRect(portal->portal_sprite->sprite);

    if (sfTime_asMilliseconds(time) > 100) {
        if (rect.left < max_left)
            rect.left += add_left;
        else
            rect.left = 0;
        sfSprite_setTextureRect(portal->portal_sprite->sprite, rect);
        sfClock_restart(portal->clock);
    }
}

void draw_boss_portal(portals_t *boss_portal, sfRenderWindow *win)
{
    drawSprite(win, boss_portal->portal_sprite->sprite, NULL);
    anim_portals(boss_portal, 2550, 320);
}

void draw_portal(portals_t *portal, sfRenderWindow *win)
{
    if (portal->see_portal == YES) {
        drawSprite(win, portal->portal_sprite->sprite, NULL);
        anim_portals(portal, 675, 225);
    }
}

void draw_all_portals(main_t *main)
{
    if (main->actual_scene == HUB) {
        for (int i = 0; i < 2; i++)
            draw_portal(main->scenes[HUB]->portals[i], main->win);
        if (main->scenes[HUB]->portals[2]->see_portal == YES)
            draw_boss_portal(main->scenes[HUB]->portals[2], main->win);
    } else {
        if (main->scenes[main->actual_scene]->portals[0] != NULL)
            draw_portal(main->scenes[main->actual_scene]->portals[0],
            main->win);
    }
}