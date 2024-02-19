##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for lib
##

SRC		=	my_getnbr.c					\
			my_putchar.c				\
			my_putstr.c					\
			my_revstr.c					\
			my_strcat.c					\
			my_strcmp.c					\
			my_strcpy.c					\
			my_strlen.c					\
			my_strdup.c					\
			str_to_word_array.c			\
			my_itoa.c					\

OBJ		=	$(SRC:.c=.o)

all:	$(OBJ)
	@ar rc libmy.a $(OBJ)
	@cp ./libmy.a ../
	@cp include/my.h ../../include/

clean:
	@rm -f $(OBJ)

.PHONY:	all clean
