/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** contain the functions of the rpg
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <math.h>
#include "my.h"
#include "map.h"
#include "entity.h"
#include "sounds.h"

#define EXIT_ERROR 84
#define UNUSED __attribute__((unused))

#define MALLOC_ERROR    "Error: malloc() exit with an error.\n"
#define SFML_ERROR      "Error: CSFML's function exit with an error.\n"
#define READ_ERROR      "Error: read() exit with error.\n"
#define CANT_OPEN_FILE  "Error: can't open necessary file to launch game.\n"

#define FONT            "ressources/font/default.otf"

#define DARK_PARTICLE   "ressources/img/particles.png"
#define BUBBLE          "ressources/img/bubbles.png"

#define ENTER_KEY       "./ressources/img/enter_key.png"

#define F_MAIN_MENU     "ressources/scenes/main_menu"
#define F_OPTION_MENU   "ressources/scenes/main_menu_option"
#define F_HOW_TO_PLAY   "ressources/scenes/how_to_play"
#define F_COMMANDS      "ressources/scenes/commands"
#define F_STORY         "ressources/scenes/story"

#define B_DEATH         "LEAVE THE GAME !!!#1500,400#30"
#define T_DEATH         "YOU ARE DEAD...#1500,400#40"

#define B_PAUSE_VOLUME "ON#1470,295#40"
#define B_PAUSE_L_ARROW "<#1350,400#100"
#define B_PAUSE_R_ARROW ">#1600,400#100"
#define B_PAUSE_GO_MENU "GO TO MENU#1000,400#30"
#define B_PAUSE_BACK "BACK TO GAME#1500,400#30"
#define T_PAUSE_TITLE "PAUSE#1500,300#60"
#define T_PAUSE_SOUNDS "SOUNDS:#960,290#40"
#define T_PAUSE_VOLUME "VOLUME:#960,490#40"
#define T_PAUSE_NBR_VOL "100#1480,490#40"

#define Vec2f sfVector2f

#define drawText(win, text, s)      sfRenderWindow_drawText(win, text, s)
#define drawSprite(win, sprite, s)  sfRenderWindow_drawSprite(win, sprite, s)
#define asMilliseconds(time)        sfTime_asMilliseconds(time)
#define setTexture(spt, txt, bool)  sfSprite_setTexture(spt, txt, bool)
#define getPosition(sprite)         sfSprite_getPosition(sprite)
#define getBounds(rect)             sfSprite_getGlobalBounds(rect)
#define rect_getGlobalBounds(rect)  sfRectangleShape_getGlobalBounds(rect)

typedef struct main_s main_t;

// Enums :
typedef enum state
{
    ON  =   1,
    OFF =   0
} state;

typedef enum scene_num
{
    MAIN_MENU   =   0,
    OPTION_MENU =   1,
    HOW_TO_PLAY =   2,
    COMMANDS    =   3,
    STORY       =   4,
    HUB         =   5,
    ASHLAND     =   6,
    CAVE        =   7,
    JUNGLE      =   8,
    ATLANTIS    =   9
} scene_num;

typedef enum line_type
{
    TAG_LINE    =   0,
    SPACER_LINE =   1,
    NORMAL_LINE =   2
} line_type;

typedef enum game_state
{
    IN_GAME     =   0,
    PAUSE       =   1,
    INVENTORY   =   2,
    STATS       =   3,
    SHOP        =   4
} game_state;

// Structures :
typedef struct text_style_s
{
    char *string;
    sfVector2f *pos;
    int charSize;
} text_style_t;

typedef struct sprite_style_s
{
    char *string;
    sfVector2f *pos;
    sfIntRect *rct;
    int rotation;
} sprite_style_t;

typedef struct sprite_s
{
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct particles_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    float speed;
} particles_t;

typedef struct button_s
{
    sfText *text;
    void (*click_fn)(main_t *main);
} button_t;

typedef struct scene_s
{
    sfText *texts[20];
    button_t *buttons[10];
    sprite_t *sprites[10];
    portals_t *portals[4];
    enemies_t *enemies[40];
    sound_t *music[10];
    particles_t *particles[60];
    rocks_t *rocks[10];
    sfFont *font;
    map_t *map;
} scene_t;

typedef struct death_menu_s
{
    sfRectangleShape *background;
    sfFont *font;
    sfText *text;
    button_t *button;
} death_menu_t;

typedef struct pause_menu_s
{
    sfRectangleShape *background;
    sfFont *font;
    sfText *text[5];
    button_t *buttons[5];
} pause_menu_t;

typedef struct options_s
{
    int volume;
    state volume_state;
} options_t;

typedef struct main_s
{
    sfRenderWindow *win;
    sfView *camera;
    sfEvent e;
    scene_t *scenes[20];
    scene_num actual_scene;
    player_t *player;
    game_state game_status;
    options_t *game_options;
} main_t;

// create_main_struct :
main_t *create_main_struct(void);

// render_scenes :
void render_menu_scene(main_t *main, scene_t *scene);
void render_game_scene(main_t *main, scene_t *scene);

// create_objects :
scene_t *create_menu_scene(char *path, void (*callbacks[4])(main_t *));
sfText *create_text(sfFont *font, char *line);
sprite_t *create_sprite(char *line);
button_t *create_button(sfFont *font, char *line, void (*)(main_t *));
scene_t *create_game_scene(char *path_layers, char *path_collision);

// particle
void move_particle(particles_t *particle);
void draw_bubble(main_t *main, particles_t *particle[30]);
int create_all_particles(main_t *main);
particles_t *create_bubble(void);

// init_game_option
options_t *init_game_option(void);

// declare the events functions
void redirect_events(main_t *main);
void event_game_handler(main_t *main);
void menu_events(main_t *main);
void menu_option_events(main_t *main);
void event_inventory_handler(main_t *main);
void event_stats_handler(main_t *main);

// event_callbacks
void launch_game(main_t *main);
void goto_options(main_t *main);
void goto_how_to_play(main_t *main);
void goto_main_menu(main_t *main);
void left_game(main_t *main);
void goto_commands(main_t *main);
void goto_story(main_t *main);

// declare the cleaning functions
void clean_program(main_t *main);
void free_tab(char **tab);
void free_text_style(text_style_t *style);
void free_sprite_style(sprite_style_t *style);

// parser :
text_style_t *parse_text_line(char *line);
sprite_style_t *parse_sprite_line(char *line);
void register_objects(FILE *scene_file, scene_t *scene,
void (*callback[4])(main_t *));
FILE *get_scene_file(char *path);
FILE *open_file(char *path);

// create_pause_menu.c
void back_to_game(main_t *main);
void pause_menu_handler(main_t *main);
pause_menu_t *create_menu_pause(void);
death_menu_t *create_death_menu(void);
void destroy_pause_menu(pause_menu_t *pause_menu);
void destroy_death_menu(death_menu_t *death_menu);
void display_pause_menu(pause_menu_t *pause_menu, sfRenderWindow *win);
void display_death_menu(main_t *main, death_menu_t *death_menu);

// pause_menu_handler.c
void handle_mouse_move_pause(pause_menu_t *pause_menu, sfVector2f pos);
void handle_mouse_released_pause(pause_menu_t *pause_menu, main_t *main,
sfVector2f pos);
void handle_mouse_click_pause(pause_menu_t *pause_menu, sfVector2f pos);
void update_pause_menu(pause_menu_t *pause_menu, main_t *main);
void death_menu_handler(death_menu_t *death_menu, main_t *main);
void update_death_menu(player_t *player);
void this_is_the_end(main_t *main);

// utils :
char *my_getline(char **line, FILE *file);
void *my_perror_null(char *err);
int my_perror(char *err);
int is_on_btn(button_t *btn, int x, int y);
int random_int(int min, int max);
float random_float(float min, float max);
char *int_to_str(int nb);
void update_view(main_t *main);

#endif // RPG_H