# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: diwalaku <diwalaku@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/27 18:11:18 by diwalaku      #+#    #+#                  #
#    Updated: 2023/07/31 17:29:05 by diwalaku      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= 		so_long
CC 		= 		gcc
GFLAGS	= 	-Wall -Werror -Wextra
SRCDIR 	= 	src/
OBJDIR 	= 	obj/

SRCFILES = main.c map_generator.c map_utils.c map_validator.c \
			free_and_error.c


SRCOBJ = $(SRCFILES:%.c=$(OBJDIR)%.o)

LIBMLX = 	./MLX42/build
LIBFT = 	./libft
HEADERS = 	-I so_long.h -I $(LIBMLX)/include -I $(LIBFT)/headers

.PHONY: all libft libmlx clean fclean re

all: libmlx libft $(NAME)

$(NAME): $(SRCOBJ)
	$(MAKE) -C $(LIBMLX)
	$(MAKE) -C $(LIBFT)
	$(CC) $(SRCOBJ) $(LIBMLX)/libmlx42.a -g3 -fsanitize=address $(LIBFT)/libft.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
# Vergeet $(GFLAGS) niet weer toe te voegen na $(CC)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p obj
	# $(CC) -c $(GFLAGS) -o $@ $<
	$(CC) -c -o $@ $<

clean:
	$(MAKE) clean -C $(LIBMLX)
	$(MAKE) clean -C $(LIBFT)
	rm -rf obj

fclean: clean
	rm -f so_long
	$(MAKE) clean -C $(LIBMLX)
#	Does LIBMLX have fclean or just clean?
	$(MAKE) fclean -C $(LIBFT)

re: fclean all