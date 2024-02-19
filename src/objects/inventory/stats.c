/*
** EPITECH PROJECT, 2020
** stats.c
** File description:
** Functions that handle the stats
*/
#include "rpg.h"

void open_stats(main_t *main)
{
    if (main->game_status != STATS)
        main->game_status = STATS;
    else if (main->game_status == STATS)
        main->game_status = IN_GAME;
}

void update_stats(player_t *player)
{
    int value[5] = {player->stats->level, player->stats->damage,
    player->stats->defense, player->stats->health, player->stats->money};
    sfVector2f pos = sfSprite_getPosition(player->sprite->sprite);
    sfVector2f pos_player = {pos.x - 70, pos.y - 120};
    sfVector2f text_pos[11] = {{pos.x - 10, pos.y - 140},
    {pos.x - 60, pos.y - 5}, {pos.x - 70, pos.y + 40},
    {pos.x - 70, pos.y + 70}, {pos.x - 70, pos.y + 100},
    {pos.x - 70, pos.y + 130}, {pos.x + 30, pos.y - 5},
    {pos.x + 30, pos.y + 40}, {pos.x + 30, pos.y + 70},
    {pos.x + 30, pos.y + 100}, {pos.x + 30, pos.y + 130}};

    for (int i = 6; i < 11; i++)
        sfText_setString(player->stats->text[i],
        int_to_str(value[i - 6]));
    for (int i = 0; i < 11; i++)
        sfText_setPosition(player->stats->text[i], text_pos[i]);
    pos.x -= 150 + 150 / 4;
    pos.y -= 150 + 150 / 4;
    sfSprite_setPosition(player->stats->sprite->sprite, pos);
    sfSprite_setPosition(player->stats->player->sprite, pos_player);
}

void draw_stats(main_t *main)
{
    if (main->game_status == STATS) {
        drawSprite(main->win, main->player->stats->sprite->sprite, NULL);
        drawSprite(main->win, main->player->stats->player->sprite, NULL);
        for (int i = 0; main->player->stats->text[i] != NULL; i++)
            sfRenderWindow_drawText(main->win,
            main->player->stats->text[i], NULL);
    }
}