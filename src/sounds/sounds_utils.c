/*
** EPITECH PROJECT, 2020
** sounds_utils.c
** File description:
** all functions can be usefull for create sounds
*/

#include "rpg.h"

void active_sounds(main_t *main)
{
    if (main->game_options->volume_state == ON) {
        main->game_options->volume_state = OFF;
        update_sounds(main, 0);
        sfText_setString(main->scenes[OPTION_MENU]->buttons[1]->text, "OFF");
        sfText_setString(main->player->pause_menu->buttons[0]->text, "OFF");
    } else if (main->game_options->volume_state == OFF) {
        main->game_options->volume_state = ON;
        update_sounds(main, main->game_options->volume);
        sfText_setString(main->scenes[OPTION_MENU]->buttons[1]->text, "ON");
        sfText_setString(main->player->pause_menu->buttons[0]->text, "ON");
    }
}

void update_sounds(main_t *main, int volume)
{
    for (int scene = 0; main->scenes[scene] != NULL; scene++) {
        for (int sd = 0; main->scenes[scene]->music[sd] != NULL; sd++)
            sfSound_setVolume(main->scenes[scene]->music[sd]->sound, volume);
        for (int i = 0; main->scenes[scene]->enemies[i] != NULL; i++)
            sfSound_setVolume(main->scenes[scene]->enemies[i]->
            dead_sounds->sound, volume);
    }
    sfSound_setVolume(main->player->player_sounds->sword_sounds->sound,
    volume);
}

void stop_all_sounds(main_t *main)
{
    for (int scene = 0; main->scenes[scene] != NULL; scene++) {
        for (int sd = 0; main->scenes[scene]->music[sd] != NULL; sd++)
            sfSound_stop(main->scenes[scene]->music[sd]->sound);
        for (int i = 0; main->scenes[scene]->enemies[i] != NULL; i++)
            sfSound_stop(main->scenes[scene]->enemies[i]->dead_sounds->sound);
    }
    sfSound_stop(main->player->player_sounds->sword_sounds->sound);
}

void set_volume_position(main_t *main, int volume)
{
    if (volume == 100)
        sfText_setPosition(main->scenes[1]->texts[3], (Vec2f){1480, 490});
    else if (volume < 100 && volume > 10)
        sfText_setPosition(main->scenes[1]->texts[3], (Vec2f){1498, 490});
    else
        sfText_setPosition(main->scenes[1]->texts[3], (Vec2f){1518, 490});
}

sound_t *create_sounds(char *music_path)
{
    sound_t *sound = malloc(sizeof(sound_t));

    if (!sound)
        return NULL;
    sound->buffer = sfSoundBuffer_createFromFile(music_path);
    if (!sound->buffer)
        return NULL;
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return sound;
}