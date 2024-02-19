/*
** EPITECH PROJECT, 2020
** event_portal.c
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

sprite_t *create_enter_key(void)
{
    sprite_t *key = malloc(sizeof(sprite_t));

    if (!key)
        return NULL;
    key->sprite = sfSprite_create();
    key->texture = sfTexture_createFromFile(ENTER_KEY, NULL);
    if (!key->sprite || !key->texture)
        return NULL;
    sfSprite_setTexture(key->sprite, key->texture, sfTrue);
    sfSprite_scale(key->sprite, (Vec2f){0.05, 0.05});
    return key;
}

void check_each_portal(portals_t *portal, player_t *player, main_t *main)
{
    sfFloatRect portal_rect = sfSprite_getGlobalBounds(portal->
    portal_sprite->sprite);
    sfFloatRect player_rect = rect_getGlobalBounds(player->hitbox);
    sfVector2f p_pos = sfRectangleShape_getPosition(main->player->hitbox);

    if (sfFloatRect_intersects(&portal_rect, &player_rect, NULL) == sfTrue &&
    main->scenes[main->actual_scene]->map->collision[(int)p_pos.y / 32]
    [(int)p_pos.x / 32] == 2 && portal->see_portal == YES)
        portal->go_in(main);
}

void display_enter_key(portals_t *portal, player_t *player, main_t *main)
{
    sfFloatRect portal_rect = sfSprite_getGlobalBounds(portal->
    portal_sprite->sprite);
    sfFloatRect player_rect = rect_getGlobalBounds(player->hitbox);
    sfVector2f p_pos = sfRectangleShape_getPosition(main->player->hitbox);

    if (sfFloatRect_intersects(&portal_rect, &player_rect, NULL) == sfTrue &&
    main->scenes[main->actual_scene]->map->collision[(int)p_pos.y / 32]
    [(int)p_pos.x / 32] == 2 && portal->see_portal == YES) {
        p_pos.y -= 55;
        p_pos.x += 20;
        sfSprite_setPosition(player->key->sprite, p_pos);
        drawSprite(main->win, player->key->sprite, NULL);
    }
}

void event_portal(player_t *player, main_t *main, int option)
{
    for (int i = 0; main->scenes[main->actual_scene]->
    portals[i] != NULL; i++) {
        if (option == 0) {
            check_each_portal(main->scenes[main->actual_scene]->portals[i],
            player, main);
        } else {
            display_enter_key(main->scenes[main->actual_scene]->portals[i],
            player, main);
        }
    }
}
