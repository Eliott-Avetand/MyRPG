/*
** EPITECH PROJECT, 2020
** register_objetcs
** File description:
** parser for scene file (register objetcs)
*/

#include "rpg.h"

line_type get_line_type(char *line, int *tag, int *i)
{
    if (line[0] == '-') {
        if (my_strcmp(line, "-TEXTS:") == 0)
            (*tag) = 0;
        else if (my_strcmp(line, "-BUTTONS:") == 0)
            (*tag) = 1;
        else
            (*tag) = 2;
        (*i) = -1;
        free(line);
        return TAG_LINE;
    } else if (my_strcmp(line, "") == 0) {
        (*i) = -1;
        free(line);
        return SPACER_LINE;
    } else
        return NORMAL_LINE;
}

void register_objects(FILE *scene_file, scene_t *scene,
void (*callback[4])(main_t *))
{
    char *line = NULL;
    int tag = 0;

    for (int i = 0; my_getline(&line, scene_file) != NULL; i++) {
        if (get_line_type(line, &tag, &i) != NORMAL_LINE)
            continue;
        if (tag == 0) {
            scene->texts[i] = create_text(scene->font, line);
            scene->texts[i + 1] = NULL;
        } else if (tag == 1) {
            scene->buttons[i] = create_button(scene->font, line, callback[i]);
            scene->buttons[i + 1] = NULL;
        } else {
            scene->sprites[i] = create_sprite(line);
            scene->sprites[i + 1] = NULL;
        }
        free(line);
    }
}