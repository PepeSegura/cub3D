# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:12:27 by psegura-          #+#    #+#              #
#    Updated: 2023/06/21 15:02:43 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###

#RESET	=	\033c
GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = cub3D

SRCS =												\
		srcs/main.c									\
													\
		srcs/parser/color.c							\
		srcs/parser/init_parse.c					\
		srcs/parser/store_textures_and_map.c		\
		srcs/parser/store_textures_and_map_utils.c	\
		srcs/parser/store_file.c					\
		srcs/parser/parser_map.c					\
													\
		srcs/draw/draw.c							\
													\
		srcs/mlx/init_mlx.c							\
		srcs/mlx/key.c								\
													\
		srcs/other/utils.c							\
													\
		srcs/raycasting/raycasting.c				\

OBJS = $(SRCS:%.c=objs/%.o)

LIB = libft/libft.a

CC = clang

# MAKEFLAGS += -j6

CFLAGS = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address
CFLAGS += -I inc
CFLAGS += -I libft
FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit 

date := $(shell date +"%a %b %_d %H:%M")

$(NAME): objs $(OBJS)
	@printf "$(GREEN)Compiling Libft:\n"
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(FLAGS_MLX) -o $(NAME)
	@echo "$(CYAN)CUB3D RIDERS GOING AFTER YOU $(WHITE)"

objs:
	@mkdir -p	objs/srcs/draw		objs/srcs/mlx			objs/srcs/other	\
				objs/srcs/parser	objs/srcs/raycasting	

objs/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf objs

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

commit: fclean
	@git add .
	@./input.sh
	@INPUT_VAR=$$(cat input.txt) && git commit -m "$(date):  $$INPUT_VAR" && rm -f input.txt
	@git push

.PHONY: all clean fclean re norma commit
