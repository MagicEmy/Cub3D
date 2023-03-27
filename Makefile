# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: emlicame <emlicame@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/21 12:19:59 by emlicame      #+#    #+#                  #
#    Updated: 2023/03/27 17:05:30 by dmalacov      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

HEADERS		:=	include/cub3D.h	 				\
				include/cub3D_defines.h 		\
				include/colors.h 				\
        		include/cub3D_structures.h
HEADERS_B	:=	include/cub3D_bonus.h	 		\
				include/cub3D_defines_bonus.h 	\
				include/colors.h 				\
        		include/cub3D_structures_bonus.h

SRC			:=	main.c 					\
				casting_get.c 			\
       			casting_rays.c 			\
				casting_utils.c 		\
				drawing.c 				\
				get_next_line.c			\
				get_next_line_utils.c	\
				hooks.c 				\
				map_equalizer.c			\
				map_validation.c   		\
				parsing.c				\
				parsing_init.c			\
				rgb_validation.c		\
				textures.c

SRC_B		:=	main_bonus.c 				\
				casting_get_bonus.c 		\
       			casting_rays_bonus.c 		\
				casting_utils_bonus.c 		\
				drawing_basic_bonus.c 		\
				drawing_bonus.c 			\
				drawing_get_bonus.c 		\
				get_next_line_bonus.c		\
				get_next_line_utils_bonus.c	\
				hooks_bonus.c 				\
				map_equalizer_bonus.c		\
				map_validation_bonus.c  	\
				parsing_bonus.c				\
				parsing_init_bonus.c		\
				rgb_validation_bonus.c		\
				textures_bonus.c

OBJ			:= $(SRC:%.c=obj/%.o)
OBJ_B		:= $(SRC_B:%.c=obj/%.o)
LIBFT		:= libft/libft.a
LIBFT_DIR	:= libft/
MLX 		:= MLX42/build/libmlx42.a
MLX_FLAGS 	:= -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
MLX_DIR 	:= MlX42/
INC			:=	-I include -I libft -I $(MLX_DIR)include
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS 		+= -g -fsanitize=address
BONUS 		= 0

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

all:	$(NAME)
	@echo "$(BOLD)$(CYAN)Cube3D Done $(RESET)$(BOLD)$(YELLOW)It's just a 🐐$(RESET)"

ifeq ($(BONUS),1)
$(NAME): $(OBJ_B) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(MLX_FLAGS) $^ -o $@
else
$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(MLX_FLAGS) $^ -o $@
endif


bonus:
	@make "BONUS = 1"

ifeq ($(BONUS),1)
obj/%.o: src/%.c $(HEADERS_B)
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
else
obj/%.o: src/%.c $(HEADERS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
endif

$(MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf obj
# @rm -rf $(MLX_DIR)/build
	$(MAKE) fclean -C $(LIBFT_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 