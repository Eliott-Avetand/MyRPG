/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** contain the functions of the rpg
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "my.h"

#define SKELETON_SPT    "ressources/img/skeleton.png"
#define PLAYER_SPT      "ressources/img/player.png"
#define INVENTORY_SPT   "ressources/img/inventory_layout.png"
#define BOSS_SPT        "ressources/img/new_boss.png"

#define STATISTICS      "STATISTICS#400,960#30"
#define LEVEL           "LEVEL#700,960#25"
#define LEVEL_VALUE     "1#700,960#25"
#define DEFENSE         "DEFENSE#800,800#20"
#define DEFENSE_VALUE   "1#800,800#20"
#define ATK             "ATTACK#800,1120#20"
#define ATK_VALUE       "1#800,1120#20"
#define HEALTH          "HEALTH#900,800#20"
#define HEALTH_VALUE    "10#900,800#20"
#define MONEY           "MONEY#900,800#20"
#define MONEY_VALUE     "0#900,800#20"

typedef struct sprite_s sprite_t;
typedef struct sound_s sound_t;
typedef struct main_s main_t;
typedef struct player_sounds_s player_sounds_t;
typedef struct inventory_sounds_s inventory_sounds_t;
typedef struct pause_menu_s pause_menu_t;
typedef struct scene_s scene_t;
typedef struct sound_s sound_t;
typedef struct death_menu_s death_menu_t;

typedef enum entity_status
{
    ALIVE       =   1,
    BEFORE_DEAD = 2,
    DEAD    =   0
} entity_status;

typedef enum attack_state
{
    WAIT            =   0,
    IS_ATTACKING    =   1
} attack_state;

typedef enum is_moving
{
    IDLE    =   0,
    MOVING  =   1,
    ATTACK  =   2,
} is_moving;

typedef enum enemy_state
{
    E_IDLE  =   0,
    E_MOVING =  1,
    E_FOLLOW =  2,
    E_ATTACK =  3
} enemy_state;

typedef enum boss_direction
{
    B_BACKWARD  =   0,
    B_LEFT      =   87,
    B_RIGHT     =   174,
    B_FORWARD   =   261
} boss_direction;

typedef enum enemy_direction
{
    E_FORWARD   =   220,
    E_DOWN      =   0,
    E_LEFT      =   75,
    E_RIGHT     =   140
} enemy_direction;

typedef enum player_direction
{
    FORWARD =   128,
    BACK    =   256,
    LEFT    =   192,
    RIGHT   =   64
} direction;

typedef enum object_status
{
    NORMAL      =   0,
    IMPORTANT   =   1
} object_status;

typedef enum object_type
{
    EQUIPMENT   =   0,
    CONSUMABLE  =   1
} object_type;

typedef struct enemy_movement_s
{
    int nbr_move;
    int what_side;
    float r_milisec;
    sfVector2f move_pos;
    sfClock *movement;
} enemy_movement_t;

typedef struct enemy_direction_s
{
    enemy_state enemy_status;
    attack_state attack_status;
    enemy_direction e_direction;
    boss_direction b_direction;
    enemy_movement_t *e_move;
    sfClock *attack_clock;
    sfClock *clock;
} enemy_direction_t;

typedef struct direction_s
{
    is_moving is_moving;
    direction direction;
    attack_state attack_status;
    sfClock *clock;
    sfClock *attack_clk;
    int floor;
} direction_t;

typedef struct objects_s
{
    sprite_t *spt;
    object_type type;
    object_status status;
    struct objects_s *next;
} objects_t;

typedef struct inventory_s
{
    sprite_t *sprite;
    inventory_sounds_t *inventory_sounds;
    objects_t *slot;
} inventory_t;

typedef struct stats_s
{
    int health;
    int max_health;
    int damage;
    int defense;
    int level;
    int money;
    int xp;
    sfFont *font;
    sfText *text[12];
    sprite_t *sprite;
    sprite_t *player;
    sound_t *stats_sound;
} stats_t;

typedef struct player_s
{
    direction_t *movement;
    inventory_t *inventory;
    stats_t *stats;
    pause_menu_t *pause_menu;
    death_menu_t *death_menu;
    entity_status player_status;
    sprite_t *sprite;
    sprite_t *key;
    sfRectangleShape *hitbox;
    sfRectangleShape *attack_box;
    sfVector2f player_pos[4];
    player_sounds_t *player_sounds;
} player_t;

typedef struct enemies_s
{
    enemy_direction_t *direction;
    sfVector2f spawn_pos;
    sprite_t *sprite;
    sound_t *dead_sounds;
    sfRectangleShape *hitbox;
    entity_status enemy_status;
    sfRectangleShape *attack_box;
    sfClock *time_death;
    int death;
    int have_attack;
    int health;
    int max_health;
    int damage;
    int defense;
} enemies_t;

// create_player
player_t *create_player(void);
inventory_t *create_inventory(void);
void destroy_player(player_t *player);

// player_attack
void update_attack_box(player_t *player, main_t *main);

// inventory
inventory_t *create_inventory(void);
void open_inventory(main_t *main);
void update_inventory(main_t *main);
void draw_inventory(main_t *main);
void destroy_inventory(inventory_t *inventory);

// stats
void open_stats(main_t *main);
void update_stats(player_t *player);
stats_t *create_stats(void);
void destroy_stats(stats_t *stats);
void draw_stats(main_t *main);

// move_player
void handle_player_movement(main_t *main);
void player_anim_movement(player_t *player);
void update_player_pos(player_t *player);
void check_floor(scene_t *scene, player_t *player);
int is_colliding(sfFloatRect bounds, sfVector2f offset, map_t *map);

// move enemy
void random_move_enemies(enemies_t *enemy, player_t *player, main_t *main);
sfVector2f new_enemy_pos(enemies_t *enemy);
void target_player(player_t *player, enemies_t *enemy, map_t *map);
void check_player(player_t *player, enemies_t *enemy);
void moving_enemy_handler(enemies_t *enemy, map_t *map);
void idle_enemy_handler(enemies_t *enemy);
void anim_enemies(enemies_t *enemy);
sfFloatRect update_bound_enemy(enemies_t *enemy);
sfVector2f get_few_distance(player_t *player, enemies_t *enemy);
void update_enemy_hitbox(enemies_t *enemy);
enemies_t *create_enemy(sfVector2f pos);
void enemi_death_management(enemies_t *enemy);
sfVector2f go_to_player(player_t *player, enemies_t *enemy, sfVector2f e_pos);

// attack_enemy.c
void anim_enemy_attack(enemies_t *enemy);
void enemy_attack_handler(enemies_t *enemy);
void update_enemy_attack_box(enemies_t *enemy, main_t *main);
void is_near_the_player(player_t *player, enemies_t *enemy);

// create_enemy
int create_all_enemies(main_t *main);
void display_enemy(scene_t *scene, main_t *main, player_t *player);
void destroy_enemy(enemies_t *enemy);
void boss_attack_clock(enemies_t *enemy);
void anim_boss(enemies_t *boss);
void display_boss(main_t *main, enemies_t *boss);
void random_move_boss(enemies_t *enemy, player_t *player, main_t *main);
int create_boss_hitbox(enemies_t *enemy);
enemies_t *create_boss(void);

#endif