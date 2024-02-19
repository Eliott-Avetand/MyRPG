/*
** EPITECH PROJECT, 2021
** create_particles.c
** File description:
** create the particles for main menu
*/

#include "rpg.h"

particles_t *create_dark_particles(void)
{
    particles_t *particle = malloc(sizeof(particles_t));
    Vec2f pos = {random_float(100, 600), random_float(750, 1080)};
    float scale = random_float(0.07, 0.2);

    if (!particle)
        return NULL;
    particle->clock = sfClock_create();
    particle->texture = sfTexture_createFromFile(DARK_PARTICLE, NULL);
    particle->sprite = sfSprite_create();
    particle->speed = random_int(1, 5);
    if (!particle->clock || !particle->sprite || !particle->texture)
        return NULL;
    sfSprite_setPosition(particle->sprite, (sfVector2f){pos.x, pos.y});
    sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
    sfSprite_setScale(particle->sprite, (Vec2f){scale, scale});
    return particle;
}

particles_t *create_bubble(void)
{
    particles_t *particle = malloc(sizeof(particles_t));
    Vec2f pos = {random_float(0, 1920), random_float(0, 1920)};
    float scale = random_float(0.9, 1.2);
    sfIntRect bubble_rect = {0, 96, 32, 32};

    if (!particle)
        return NULL;
    particle->clock = sfClock_create();
    particle->texture = sfTexture_createFromFile(BUBBLE, NULL);
    particle->sprite = sfSprite_create();
    particle->speed = random_int(1, 2);
    if (!particle->clock || !particle->sprite || !particle->texture)
        return NULL;
    sfSprite_setPosition(particle->sprite, (sfVector2f){pos.x, pos.y});
    sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
    sfSprite_setTextureRect(particle->sprite, bubble_rect);
    sfSprite_setScale(particle->sprite, (Vec2f){scale, scale});
    return particle;
}

void move_particle(particles_t *particle)
{
    sfInt32 time = asMilliseconds(sfClock_getElapsedTime(particle->clock));
    Vec2f pos = sfSprite_getPosition(particle->sprite);

    if (time >= particle->speed) {
        pos.y -= particle->speed * 5;
        sfSprite_setPosition(particle->sprite, pos);
        sfClock_restart(particle->clock);
    }
    if (pos.y <= 100) {
        pos.y = random_int(750, 1080);
        sfSprite_setPosition(particle->sprite, pos);
    }
}

void draw_bubble(main_t *main, particles_t **particles)
{
    sfInt32 time;
    Vec2f pos;

    for (int i = 0; particles[i] != NULL; i++) {
        time = asMilliseconds(sfClock_getElapsedTime(particles[i]->clock));
        pos = sfSprite_getPosition(particles[i]->sprite);
        drawSprite(main->win, particles[i]->sprite, NULL);
        if (time >= particles[i]->speed) {
            pos.y -= particles[i]->speed * 5;
            sfSprite_setPosition(particles[i]->sprite, pos);
            sfClock_restart(particles[i]->clock);
        }
        if (pos.y <= 100) {
            pos.y = random_int(750, 1080);
            sfSprite_setPosition(particles[i]->sprite, pos);
        }
    }
}

int create_all_particles(main_t *main)
{
    for (int i = 0; i < 30; i++) {
        main->scenes[0]->particles[i] = create_dark_particles();
        main->scenes[1]->particles[i] = create_dark_particles();
        main->scenes[0]->particles[i + 1] = NULL;
        main->scenes[1]->particles[i + 1] = NULL;
        if (!main->scenes[0]->particles[i] || !main->scenes[1]->particles[i])
            return EXIT_ERROR;
    }
    return 0;
}