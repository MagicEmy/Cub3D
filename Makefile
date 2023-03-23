# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 12:19:59 by emlicame          #+#    #+#              #
#    Updated: 2023/03/22 15:10:20 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D
HEADERS		:=	include/cub3D.h	 		\
				include/cub3D_defines.h \
				include/colors.h \
       			include/cub3D_structures.h

SRC			:=	main.c \
				parsing.c				\
				parsing_init.c			\
				get_next_line.c			\
				get_next_line_utils.c	\
				info_validation.c		\
				map_validation.c   		\
				map_equalizer.c			\
       			casting_rays.c \
				casting_utils.c \
				casting_get.c \
				drawing.c \
				drawing_bonus.c \
				hooks.c \
				textures.c
# to do: deal with bonus files

SRC_B		:=	b_main.c 				\
				b_parsing.c				\
				b_parsing_init.c		\
				b_get_next_line.c		\
				b_get_next_line_utils.c	\
				b_info_validation.c		\
				b_map_validation.c  	\
				b_map_equalizer.c		\
       			b_casting_rays.c 		\
				b_casting_utils.c 		\
				b_casting_get.c 		\
				b_drawing.c 			\
				b_drawing_bonus.c 		\
				b_hooks.c 				\
				b_textures.c

OBJ			:= $(SRC:%.c=obj/%.o)
LIBFT		:= libft/libft.a
LIBFT_DIR	:= libft/
MLX 		:= MLX42/build/libmlx42.a
MLX_FLAGS 	:= -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
MLX_DIR 	:= MlX42/
INC			:=	-I include -I libft -I $(MLX_DIR)include
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS 		+= -g -fsanitize=address

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

ifdef BONUS
	OBJ = $(SRC_B:%.c=b_obj/%.o)
endif

all:	$(NAME)
	@echo "$(BOLD)$(CYAN)Cube3D Done $(RESET)$(BOLD)$(YELLOW)It's just a 🐐$(RESET)"

#  commented out - version including references to LIBFT
$(NAME): $(OBJ) $(HEADERS) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

#  without LIBFT - to be deleted once LIBFT is in place
# $(NAME): $(OBJ) $(HEADERS) $(MLX)
# 	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(MLX) $(MLX_FLAGS) -o $(NAME) 

bonus:	
	@make BONUS=1

obj/%.o: src/%.c $(HEADERS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

b_obj/%.o: src_b/%.c $(HEADERS)
	@mkdir -p b_obj
	@$(CC) $(INC) $(CFLAGS) -o $@ -c $<

$(MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf obj
	@rm -rf b_obj
# @rm -rf $(MLX_DIR)/build
	$(MAKE) fclean -C $(LIBFT_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re