/*
** EPITECH PROJECT, 2020
** event_game.c
** File description:
** create pause menu
*/
#include "rpg.h"

void analyse_key_game(main_t *main)
{
    if (main->e.key.code == sfKeyEnter)
        event_portal(main->player, main, 0);
    if (main->e.key.code == sfKeyI) {
        update_inventory(main);
        open_inventory(main);
    } else if (main->e.key.code == sfKeyC) {
        update_stats(main->player);
        open_stats(main);
    } else
        handle_player_movement(main);
}

void event_player_alive(main_t *main)
{
    if (main->game_status == IN_GAME) {
        if (main->e.type == sfEvtKeyPressed)
            analyse_key_game(main);
        if (main->e.type == sfEvtKeyReleased &&
        main->player->movement->is_moving != ATTACK)
            main->player->movement->is_moving = IDLE;
        return;
    } else if (main->game_status == PAUSE) {
        pause_menu_handler(main);
        return;
    }
    if (main->game_status == INVENTORY)
        event_inventory_handler(main);
    else if (main->game_status == STATS)
        event_stats_handler(main);
}

void event_game_handler(main_t *main)
{
    if (main->player->player_status != DEAD)
        event_player_alive(main);
    else
        death_menu_handler(main->player->death_menu, main);
}
