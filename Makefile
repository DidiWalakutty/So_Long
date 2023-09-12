# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: diwalaku <diwalaku@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/27 18:11:18 by diwalaku      #+#    #+#                  #
#    Updated: 2023/09/12 17:49:36 by diwalaku      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= 		so_long
CC 		= 		gcc
GFLAGS	= 	-Wall -Werror -Wextra
# GFLAGS  +=	-fsanitize=address -g
SRCDIR 	= 	src/
OBJDIR 	= 	obj/

SRCFILES = main.c map_generator.c map_finder.c map_validator.c \
			map_checker.c render.c free_and_error.c \
			load_window.c load_sprites.c keyboard.c \
			moves.c window.c enemy.c \

SRCOBJ = $(SRCFILES:%.c=$(OBJDIR)%.o)

LIBMLX = 	./MLX42/build
LIBFT = 	./libft
HEADERS = 	-I so_long.h -I $(LIBMLX)/include -I $(LIBFT)/headers

.PHONY: all libft libmlx clean fclean re

all: libmlx libft $(NAME)

$(NAME): $(SRCOBJ)
	$(MAKE) -C $(LIBMLX)
	$(MAKE) -C $(LIBFT)
	$(CC) $(GFLAGS) $(SRCOBJ) $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p obj
	$(CC) -c $(GFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C $(LIBMLX)
	$(MAKE) clean -C $(LIBFT)
	rm -rf obj

fclean: clean
	rm -f so_long
	$(MAKE) clean -C $(LIBMLX)
	$(MAKE) fclean -C $(LIBFT)

re: fclean all