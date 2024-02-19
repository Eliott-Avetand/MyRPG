/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** contain the functions of the rpg (maps)
*/

#ifndef RPG_MAP_H
#define RPG_MAP_H

#define HUB_LAYERS_LIST         "ressources/maps/hub/layers_list"
#define HUB_COLLISON_MAP        "ressources/maps/hub/collision_map"
#define ASHLAND_LAYERS_LIST     "ressources/maps/ashland/layers_list"
#define ASHLAND_COLLISION_MAP   "ressources/maps/ashland/collision_map"
#define CAVE_LAYERS_LIST        "ressources/maps/cave/layers_list"
#define CAVE_COLLISION_MAP      "ressources/maps/cave/collision_map"
#define ATLANTIS_LAYERS_LIST    "ressources/maps/atlantis/layers_list"
#define ATLANTIS_COLLISION_MAP  "ressources/maps/atlantis/collision_map"
#define JUNGLE_LAYERS_LIST      "ressources/maps/jungle/layers_list"
#define JUNGLE_COLLISON_MAP     "ressources/maps/jungle/collision_map"

#define ORANGE_PORTAL   "ressources/img/orange_portal.png"
#define BOSS_PORTAL     "ressources/img/boss_portal.png"
#define GREEN_PORTAL    "ressources/img/green_portal.png"

#define ROCKS           "ressources/img/rocks.png"

typedef struct main_s main_t;
typedef struct sprite_s sprite_t;
typedef struct player_s player_t;
typedef struct pause_menu_s pause_menu_t;
typedef struct scene_s scene_t;

typedef enum visibility
{
    YES =   1,
    NO  =   0
} visibility;

typedef struct portals_s
{
    sprite_t *portal_sprite;
    sfClock *clock;
    sfVector2f tp_position;
    visibility see_portal;
    void (*go_in)(main_t *main);
} portals_t;

typedef struct rocks_s
{
    sprite_t *sprite;
    sfClock *clock;
    visibility see_rocks;
} rocks_t;

typedef struct map_s
{
    sprite_t *layers[20];
    int **collision;
    sfRectangleShape **coll_rect;
} map_t;

// create_rocks
void destroy_all_rocks(scene_t *scene);
void rocks_animation(rocks_t *rocks);
int create_all_rocks(main_t *main);
void display_rocks(scene_t *scene, main_t *main);
void check_all_crystals(main_t *main);

// create_collision_rect :
int create_collision_rect(map_t *map);

// create_portals.c
void create_all_portals(main_t *main);
void check_tp_in_cave(main_t *main);

// event_portal.c
void display_enter_key(portals_t *portal, player_t *player, main_t *main);
void event_portal(player_t *player, main_t *main, int option);
sprite_t *create_enter_key();

// portals_callbacks
void go_ashland(main_t *main);
void go_jungle(main_t *main);
void go_boss(main_t *main);
void go_in_cave(main_t *main);
void check_portals(main_t *main);

// anim portals.c
void anim_portals(portals_t *portal, int max_left, int add_left);
void draw_portals(portals_t *portal, sfRenderWindow *win);
void draw_all_portals(main_t *main);

// destroy_portals.c
void destroy_all_portals(main_t *main);

#endif