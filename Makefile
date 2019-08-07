# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:28:04 by lschambe          #+#    #+#              #
#    Updated: 2019/04/03 15:10:40 by lschambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

FLAG = -Wall -Werror -Wextra

OBJ1 = create_stack.c commands.c helps_stack.c stack_making.c \
help_making.c help_stack_2.c help_create_stack.c help_create_stack2.c

OBJ2 = checker.c commands.c stack_making.c helps_stack.c help_making.c execute.c

LIB_OBJ = $(patsubst %.c,%.o,$(wildcard libft/*.c))

OBJ_ONE = $(patsubst %.c,%.o,$(OBJ1))

OBJ_TWO = $(patsubst %.c,%.o,$(OBJ2))

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ_ONE) $(LIB_OBJ)
	gcc $(FLAG) $^ -o $@

$(NAME2): $(OBJ_TWO) $(LIB_OBJ)
	gcc $(FLAG) $^ -o $@

%.o: %.c
	gcc $(FLAG) -c $^ -o $@ -Ilibft

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f libft/*.o

re : fclean all

.PHONY: all clean fclean re
