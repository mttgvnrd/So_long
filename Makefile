# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:14:54 by mgiovana          #+#    #+#              #
#    Updated: 2023/03/03 15:26:07 by mgiovana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c map_error.c game_utils.c put_map.c movement.c move_counter.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIE

LINK = ../minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm

LIBFT = ./src/libft/libft.a

GNL = ./src/GNL/GNL.a

PRINTF = ./src/Printf/libftprintf.a

all: lib printf gnl $(NAME)

lib:
	make -s -C src/libft

printf:
	make -s -C src/Printf
        
gnl:
	make -s -C src/GNL
	
$(NAME): $(OBJ)
	@echo "\033[32mCompiling $(NAME) 🚀"
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(LINK) -o $(NAME)
	@echo "Compiled ✅\033[0;37m"

clean:
	@echo "\033[0;31mCleaning objects 🧹"
	@rm -rf $(OBJ)
	@make clean -s -C src/libft
	@make clean -s -C src/Printf
	@make clean -s -C src/GNL

fclean: clean
	@echo "\033[0;31mRemoving $(NAME) 🗑\033[0;37m"
	@rm -rf $(NAME)
	@make fclean -s -C src/libft
	@make fclean -s -C src/Printf
	@make fclean -s -C src/GNL

re: fclean all

.SILENT: $(OBJ) lib printf gnl
