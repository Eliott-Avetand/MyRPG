/*
** EPITECH PROJECT, 2020
** render_scenes
** File description:
** render_scenes
*/

#include "rpg.h"

void render_player(main_t *main)
{
    sfSprite_setOrigin(main->player->sprite->sprite, (sfVector2f){16, 16});
    drawSprite(main->win, main->player->sprite->sprite, NULL);
    sfSprite_setOrigin(main->player->sprite->sprite, (sfVector2f){0, 0});
}

void render_menu_scene(main_t *main, scene_t *scene)
{
    sfRenderWindow_clear(main->win, sfBlack);
    drawSprite(main->win, scene->sprites[0]->sprite, NULL);
    for (int i = 0; scene->buttons[i] != NULL; i++)
        drawText(main->win, scene->buttons[i]->text, NULL);
    for (int i = 0; scene->texts[i] != NULL; i++)
        drawText(main->win, scene->texts[i], NULL);
    for (int i = 1; scene->sprites[i] != NULL; i++)
        drawSprite(main->win, scene->sprites[i]->sprite, NULL);
    for (int i = 0; scene->particles[i] != NULL; i++) {
        drawSprite(main->win, scene->particles[i]->sprite, NULL);
        move_particle(scene->particles[i]);
    }
    sfRenderWindow_display(main->win);
}

void draw_other_objects(main_t *main, scene_t *scene)
{
    if (main->actual_scene == ATLANTIS)
        display_boss(main, main->scenes[ATLANTIS]->enemies[0]);
    else
        display_enemy(scene, main, main->player);
    display_rocks(scene, main);
    draw_all_portals(main);
    event_portal(main->player, main, 1);
    check_tp_in_cave(main);
    check_floor(scene, main->player);
    draw_inventory(main);
    draw_stats(main);
    this_is_the_end(main);
    display_death_menu(main, main->player->death_menu);
}

void render_game_scene(main_t *main, scene_t *scene)
{
    int i = 0;

    sfRenderWindow_clear(main->win, sfBlack);
    while (scene->map->layers[i + 1] != NULL)
        drawSprite(main->win, scene->map->layers[i++]->sprite, NULL);
    if (main->game_status == IN_GAME && main->actual_scene == ATLANTIS)
        draw_bubble(main, main->scenes[main->actual_scene]->particles);
    if (main->game_status == IN_GAME)
        player_anim_movement(main->player);
    if (main->player->player_status != DEAD)
        render_player(main);
    drawSprite(main->win, scene->map->layers[i]->sprite, NULL);
    draw_other_objects(main, scene);
    if (main->game_status == PAUSE)
        display_pause_menu(main->player->pause_menu, main->win);
    sfRenderWindow_display(main->win);
}