/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** contain the functions of the rpg
*/

#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

#define MENU_MUSIC      "ressources/sounds/menu_theme.ogg"
#define OPTION_MUSIC    "ressources/sounds/option_theme.ogg"
#define SELECT_MENU     "ressources/sounds/select_menu.ogg"

#define ATLANTIS_MUSIC  "ressources/sounds/boss_ost.ogg"
#define ASHLAND_MUSIC   "ressources/sounds/ashland.ogg"
#define HUB_MUSIC       "ressources/sounds/hub.ogg"
#define JUNGLE_MUSIC    "ressources/sounds/jungle.ogg"

#define SWORD_SOUND     "ressources/sounds/sword_sound.ogg"
#define HIT_SOUND       "ressources/sounds/hit.ogg"
#define OPEN_INVENTORY  "ressources/sounds/inventory_open.ogg"
#define OPEN_STATS      "ressources/sounds/stats_open.ogg"

#define ENEMY_DEATH     "ressources/sounds/skeleton_death.ogg"
#define BOSS_DEATH      "ressources/sounds/boss_cry.ogg"

typedef struct main_s main_t;
typedef struct scene_s scene_t;
typedef enum scene_num scene_num;

typedef struct sound_s
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct player_sounds_s
{
    sound_t *hit;
    sound_t *sword_sounds;
} player_sounds_t;

typedef struct inventory_sounds_s
{
    sound_t *open;
} inventory_sounds_t;

// sounds_utils.c
void active_sounds(main_t *main);
void update_sounds(main_t *main, int volume);
void set_volume_position(main_t *main, int volume);
void stop_all_sounds(main_t *main);
sound_t *create_sounds(char *music_path);

// sounds_callbacks.c
void increase_audio(main_t *main);
void decrease_audio(main_t *main);

// create_sounds.c
int create_game_sounds(main_t *main);
int create_menu_sounds(main_t *main);
player_sounds_t *create_player_sounds(void);
inventory_sounds_t *create_inventory_sounds(void);
sound_t *create_stats_sounds(void);

// destroy_sounds.c
void destroy_game_sounds(main_t *main);
void destroy_player_sounds(player_sounds_t *player_sounds);
void destroy_inventory_sounds(inventory_sounds_t *inventory_sounds);
void destroy_stats_sounds(sound_t *stats_sound);

#endif