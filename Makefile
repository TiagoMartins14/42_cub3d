# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:27:06 by tiaferna          #+#    #+#              #
#    Updated: 2024/05/15 16:44:21 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

RESET	= \033[0m
BOLD	= \033[1m
FAINT	= \033[2m
ITALIC	= \033[3m
ULINE	= \033[4m
SBLINK	= \033[5m
FBLINK	= \033[6m
REVCOL	= \033[7m
HIDDEN	= \033[8m
CROSS	= \033[9m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

SRCS_DIR		= src

OBJS_DIR		= objs

LMLX_DIR		= minilibx-linux

INCLUDES		= includes
LIBFT			= ./libs/libft/libft.a
LIBFT_DIR		= ./libs/libft

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
LFLAGS			= -L$(LIBFT_DIR) -lft -L$(LMLX_DIR) -lmlx

ifeq ($(FOUND_OS), Darwin)
	CC			= gcc
	LFLAGS		+= -framework OpenGL -framework AppKit
else ifeq ($(FOUND_OS), FreeBSD)
	CC			= clang
else
	CC			= cc
	LFLAGS		+= -lbsd -lXext -lX11 -lm
endif

RM				= rm -rf

SRCS			=	free_mem.c \
					map_checkers_1.c \
					map_checkers_2.c \
					map_creators.c \
					map_parameters_checker.c \
					parser.c \
					player_utils.c \
					printers.c \
					rgb_getter.c \
					struct_init.c \
					textures_geter.c

# Substitute .c with .o 
OBJS			= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	clear
	@echo "$(GREEN)./cub3d executable is ready!$(RESET)"

#create .o fies
# $< first prerequisite aka .c; $@ output/target file aka .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	clear
	@echo "$(YELLOW)Compiling necessary libs...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LMLX_DIR)

#remove .o files
clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	cd minilibx-linux && make clean
	clear
	@echo "$(RED)Object files have been deleted!$(RESET)"

#reset environment - remove everything and recompile
fclean: clean
	$(RM) $(NAME) $(LIBFT)
	clear
	@echo "$(RED)Object files and executable have been deleted!$(RESET)"

re: fclean all

download:
	@ wget https://cdn.intra.42.fr/document/document/22624/minilibx-linux.tgz
	@ tar -xzf minilibx-linux.tgz
	@ rm minilibx-linux.tgz

#targets declared as .PHONY will force the command even if there is a subdirectory or file with it's name
.PHONY: all clean fclean re