# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:12:27 by psegura-          #+#    #+#              #
#    Updated: 2023/07/13 19:39:49 by hakahmed         ###   ########.fr        #
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
		srcs/parser/map_to_int.c					\
		srcs/parser/parser_map.c					\
		srcs/parser/parser_map_aux.c				\
		srcs/parser/check_borders.c					\
		srcs/parser/fill_map_with_spaces.c			\
													\
		srcs/draw/draw.c							\
													\
													\
		srcs/other/utils.c							\
													\
		srcs/raycasting/raycasting.c				\
		srcs/mlx/key.c								\
		srcs/mlx/init_mlx.c							\
		srcs/raycasting/minimap.c

INC =												\
		inc/cub3d.h									\
		inc/defines.h								\
		inc/errors.h								\
		inc/libs.h									\
		inc/structures.h							\
		
OBJS = $(SRCS:%.c=objs/%.o)

LIB = libft/libft.a

CC = cc

# MAKEFLAGS += -j6

OS = $(shell uname -s)

CFLAGS = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address
CFLAGS += -I inc
CFLAGS += -I libft/inc
CFLAGS += -g3
CFLAGS += -O3

ifeq ($(OS),Darwin)
	CFLAGS += -D OSX
	FLAGS_MLX =  -lmlx -framework OpenGL -framework AppKit 
endif
ifeq ($(OS),Linux)
	CFLAGS += -D LINUX
	CFLAGS += -fsanitize=leak -g3
	FLAGS_MLX =  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
	FLAGS_MLX +=  -fsanitize=leak
	CFLAGS += -I/usr/include -Imlx_linux
endif

date := $(shell date +"%a %b %_d %H:%M")

$(NAME): $(INC) objs $(OBJS)
	@printf "$(GREEN)Compiling Libft:\n"
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(FLAGS_MLX) -o $(NAME)
	@echo "$(CYAN)CUB3D RIDERS GOING AFTER YOU $(WHITE)"

objs:
	@mkdir -p	objs/srcs/draw		objs/srcs/mlx			objs/srcs/other	\
				objs/srcs/parser	objs/srcs/raycasting	

objs/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf objs

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)


norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

commit: fclean
	@git add .
	@./input.sh
	@INPUT_VAR=$$(cat input.txt) && git commit -m "$(date):  $$INPUT_VAR" && rm -f input.txt
	@git push

.PHONY: all clean fclean re norma commit

re:: fclean
re:: all
