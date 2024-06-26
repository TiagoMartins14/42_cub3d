# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 10:36:01 by jrocha-v          #+#    #+#              #
#    Updated: 2024/06/06 18:30:49 by jrocha-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

SRCS_DIR		= src

OBJS_DIR		= objs

INCLUDES		= includes
LIBFT			= ./libs/libft/libft.a
LIBFT_DIR		= ./libs/libft
LIBMLX			= ./libs/minilibx-linux/libmlx.a
LIBMLX_DIR		= ./libs/minilibx-linux

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS		= -lmlx_Linux -lXext -lX11 -lm -lbsd

MK_FLAG			= --no-print-directory
RM				= rm -rf

SRCS			= 	parser/free_mem.c \
					parser/map_checkers_1.c \
					parser/map_checkers_2.c \
					parser/map_creators.c \
					parser/map_parameters_checker.c \
					parser/parser.c \
					parser/player_utils.c \
					parser/printers.c \
					parser/rgb_getter.c \
					parser/struct_init.c \
					parser/textures_geter.c \
					main.c \
					init.c 	\
					events.c \
					player.c \
					player_move.c \
					minimap.c \
					raycast.c \
					raycast_dda.c \
					render.c \
					draw_utils.c \
					utils.c \
					error.c

# Substitute .c with .o 
OBJS			= $(SRCS:%.c=$(OBJS_DIR)/%.o)

#default target
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBMLX_DIR) $(MLX_FLAGS) $(LIBFT) -o $(NAME)
	echo "Finished!"

#create .o files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo "Compiling necessary libs..."
	$(MAKE) $(MK_FLAG) -C $(LIBFT_DIR)

$(LIBMLX):
	echo "Compiling necessary libs..."
	$(MAKE) $(MK_FLAG) -C $(LIBMLX_DIR)

#remove .o files
clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX)

#reset - remove and recompile
re: fclean
	$(MAKE) all

download:
	@ wget https://cdn.intra.42.fr/document/document/22624/minilibx-linux.tgz
	@ tar -xzf minilibx-linux.tgz -C libs
	@ rm minilibx-linux.tgz

.PHONY: all clean fclean re
.SILENT:
