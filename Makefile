# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 18:11:18 by diwalaku          #+#    #+#              #
#    Updated: 2024/02/11 14:28:47 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 		so_long
CFLAGS	= 		-Wall -Werror -Wextra
RM		=		rm -rf
SRCDIR 	= 		src/
OBJDIR 	= 		obj/

SRCFILES = main.c map_processor.c map_path_finder.c map_validator.c \
			map_checker.c place_render.c free_and_error.c \
			load_window.c load_sprites.c keyboard_and_messages.c \
			moves.c window.c enemy.c \

SRCOBJ = $(SRCFILES:%.c=$(OBJDIR)%.o)

SO_LONG = so_long

MLX42 = 	MLX42/build/libmlx42.a
LIBFT = 	./libft/libft.a
HEADERS = 	-I ./include -I ./MLX42/include -I ./libft/libft.h

ifeq ($(shell uname -s),Darwin)			# Mac
	MLXFLAGS = MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
else ifeq ($(shell uname -s),Linux)		# Linux
	MLXFLAGS = MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
endif

# Colors
RESET = \033[0m
YELLOW = \33[1;43m
BLUE=\033[1;44m
RED=\033[0;41m
PURPLE=\033[45m
CORAL=\033[38;2;255;127;80m

.PHONY: all libft libmlx clean fclean re

all: $(SO_LONG)

$(SO_LONG): $(SRCOBJ) $(MLX42) $(LIBFT)
	cc $(CFLAGS) $(SRCOBJ) $(MLXFLAGS) $(MLX42) $(LIBFT) -o $(SO_LONG)
	@echo "\n$(PURPLE)Created executable for the $(SO_LONG) file$(RESET)\n\n"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p obj
	@cc -c $(CFLAGS) -o $@ $<

$(LIBFT):
	make -C libft

$(MLX42):
	cmake MLX42 -B MLX42/build
	make -C MLX42/build

clean:
	$(RM) $(OBJDIR)
	@echo "\n$(CORAL)Removed all .o files and its directory$(RESET)\n\n"

fclean: clean
	$(RM) $(SO_LONG)
	@rm -rf MLX42/build
	make fclean -C libft
	@echo "\n$(RED)Cleaned up remaining files$(RESET)\n\n"

re: fclean all