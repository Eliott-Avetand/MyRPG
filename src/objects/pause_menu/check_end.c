/*
** EPITECH PROJECT, 2020
** create_pause_menu
** File description:
** create pause menu
*/

#include "rpg.h"

void this_is_the_end(main_t *main)
{
    sfVector2f pos = {0, 0};

    if (main->scenes[ATLANTIS]->enemies[0]->enemy_status == DEAD) {
        update_death_menu(main->player);
        pos = sfText_getPosition(main->player->death_menu->text);
        sfText_setString(main->player->death_menu->text, "YOU WIN GAME!!");
        pos.x += 5;
        sfText_setPosition(main->player->death_menu->text, pos);
        main->player->player_status = DEAD;
    }
}