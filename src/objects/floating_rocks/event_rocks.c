/*
** EPITECH PROJECT, 2021
** create_collision_rect
** File description:
** create_collision_rect
*/

#include "rpg.h"

int got_a_crytals(rocks_t *rocks, player_t *player)
{
    sfFloatRect p_rect = sfRectangleShape_getGlobalBounds(player->hitbox);
    sfFloatRect r_rect = sfSprite_getGlobalBounds(rocks->sprite->sprite);

    if (sfFloatRect_intersects(&p_rect, &r_rect, NULL) == sfTrue)
        return 1;
    return 0;
}

void check_all_crystals(main_t *main)
{
    if (main->actual_scene == CAVE) {
        if (got_a_crytals(main->scenes[CAVE]->rocks[0], main->player) == 1) {
            main->scenes[CAVE]->rocks[0]->see_rocks = NO;
            main->scenes[HUB]->rocks[0]->see_rocks = YES;
            main->scenes[HUB]->portals[0]->see_portal = NO;
        }
    } if (main->actual_scene == JUNGLE) {
        if (got_a_crytals(main->scenes[JUNGLE]->rocks[0], main->player) == 1) {
            main->scenes[JUNGLE]->rocks[0]->see_rocks = NO;
            main->scenes[HUB]->rocks[1]->see_rocks = YES;
            main->scenes[HUB]->portals[1]->see_portal = NO;
        }
    }
    if (main->scenes[CAVE]->rocks[0]->see_rocks == NO &&
    main->scenes[JUNGLE]->rocks[0]->see_rocks == NO)
        main->scenes[HUB]->portals[2]->see_portal = YES;
}