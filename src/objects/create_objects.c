/*
** EPITECH PROJECT, 2020
** create_objects
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

scene_t *create_menu_scene(char *path, void (*callbacks[4])(main_t *))
{
    scene_t *scene = malloc(sizeof(scene_t));
    FILE *scene_file = get_scene_file(path);

    if (!scene || !scene_file)
        return my_perror_null("Can't get style file.\n");
    scene->font = sfFont_createFromFile(FONT);
    scene->texts[0] = NULL;
    scene->buttons[0] = NULL;
    scene->sprites[0] = NULL;
    scene->particles[0] = NULL;
    scene->music[0] = NULL;
    scene->enemies[0] = NULL;
    scene->rocks[0] = NULL;
    scene->map = NULL;
    if (!scene->font)
        return NULL;
    register_objects(scene_file, scene, callbacks);
    fclose(scene_file);
    return scene;
}

sfText *create_text(sfFont *font, char *line)
{
    sfText *text = sfText_create();
    text_style_t *style = parse_text_line(line);
    sfFloatRect bounds;

    if (!text || !font || !style)
        return my_perror_null(SFML_ERROR);
    sfText_setCharacterSize(text, style->charSize);
    sfText_setFont(text, font);
    sfText_setString(text, style->string);
    bounds = sfText_getGlobalBounds(text);
    sfText_setOrigin(text, (Vec2f){bounds.width / 2, bounds.height / 2});
    sfText_setPosition(text, (*style->pos));
    free_text_style(style);
    return text;
}

button_t *create_button(sfFont *font, char *line, void (*click_fn)(main_t *))
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    button->text = create_text(font, line);
    button->click_fn = click_fn;
    if (!button->text)
        return NULL;
    return button;
}

sprite_t *create_sprite(char *line)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite_style_t *style = parse_sprite_line(line);

    if (!sprite || !style)
        return my_perror_null(MALLOC_ERROR);
    sprite->texture = sfTexture_createFromFile(style->string, NULL);
    sprite->sprite = sfSprite_create();
    if (!sprite->sprite || !sprite->sprite)
        return my_perror_null(SFML_ERROR);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, *style->pos);
    sfSprite_setTextureRect(sprite->sprite, *style->rct);
    sfSprite_setRotation(sprite->sprite, style->rotation);
    free_sprite_style(style);
    return sprite;
}