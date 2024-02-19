##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## create the program
##

SRC		=	main.c											\
			src/objects/create_main_struct.c				\
			src/objects/render_scenes.c						\
			src/objects/create_objects.c					\
			src/objects/create_particles.c					\
			src/objects/create_game_scene.c					\
			src/objects/create_collision_rect.c				\
			src/objects/is_colliding.c						\
			src/objects/boss/anim_boss.c					\
			src/objects/boss/create_boss.c					\
			src/objects/player/create_player.c				\
			src/objects/player/move_player.c				\
			src/objects/player/attack_player.c				\
			src/objects/player/anim_player.c				\
			src/objects/player/player_scaling.c				\
			src/objects/init_game_option.c					\
			src/objects/portals/create_portals.c			\
			src/objects/portals/anim_portals.c				\
			src/objects/portals/clean_portals.c				\
			src/objects/portals/portal_callback.c			\
			src/objects/pause_menu/create_pause_menu.c		\
			src/objects/pause_menu/pause_menu_handler.c		\
			src/objects/pause_menu/display_pause_menu.c		\
			src/objects/pause_menu/create_death_menu.c		\
			src/objects/pause_menu/display_death_menu.c		\
			src/objects/pause_menu/check_end.c				\
			src/objects/enemies/anim_enemies.c				\
			src/objects/enemies/attack_enemies.c			\
			src/objects/enemies/clean_enemies.c				\
			src/objects/enemies/create_all_enemies.c		\
			src/objects/enemies/death_enemies.c				\
			src/objects/enemies/display_enemies.c			\
			src/objects/enemies/enemies_move.c				\
			src/objects/enemies/init_enemies.c				\
			src/objects/enemies/target_player.c				\
			src/objects/inventory/create_inventory.c		\
			src/objects/inventory/create_stats.c			\
			src/objects/inventory/destroy_stats.c			\
			src/objects/inventory/destroy_inventory.c		\
			src/objects/inventory/inventory.c				\
			src/objects/inventory/stats.c					\
			src/objects/floating_rocks/create_rocks.c		\
			src/objects/floating_rocks/display_rocks.c		\
			src/objects/floating_rocks/event_rocks.c		\
			src/sounds/destroy_sounds.c						\
			src/sounds/sounds_menu.c						\
			src/sounds/sounds_utils.c						\
			src/sounds/sounds_callbacks.c					\
			src/sounds/player_sounds.c						\
			src/sounds/inventory_sounds.c					\
			src/events/redirect_events.c					\
			src/events/event_callbacks.c					\
			src/events/event_callbacks2.c					\
			src/events/event_inventory.c					\
			src/events/event_game.c							\
			src/events/event_stats.c						\
			src/events/event_in_cave.c						\
			src/events/event_portal.c						\
			src/clean/clean_program.c						\
			src/clean/destroy_objects.c						\
			src/clean/free_tab.c							\
			src/utils/parser/register_objects.c				\
			src/utils/parser/parser_checker.c				\
			src/utils/parser/parse_line.c					\
			src/utils/my_getline.c							\
			src/utils/random.c								\
			src/utils/int_to_str.c							\
			src/utils/my_perror.c						 	\
			src/utils/text_utils.c							\
			src/utils/update_view.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	+=	-W -Wall -Wextra -I./include

INCLUDES	= -L./lib -lmy -I./include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

.PHONY: all
all:	$(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean:	clean
	rm -f $(NAME)

.PHONY: re
re:	clean all

.PHONY: debug
debug:	fclean
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(INCLUDES) -g

.PHONY: tests_run
tests_run:
	gcc -o unit_test project.c tests/test_project.c -lcriterion
	./unit_test

.PHONY: ${NAME}
$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(INCLUDES)
