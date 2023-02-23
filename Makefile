# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: emlicame <emlicame@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/21 12:19:59 by emlicame      #+#    #+#                  #
#    Updated: 2023/02/23 19:11:22 by dmalacov      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D
HEADERS		:=	include/cub3D.h	 \
				include/cub3D_defines.h \
				include/colors.h

SRC			:=	main.c \
				casting_rays.c \
				casting_utils.c
				
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

all:	$(NAME)
	@echo "$(BOLD)$(CYAN)Cube3D Done $(RESET)$(BOLD)$(YELLOW)It's just a 🐐$(RESET)"

#  commented out - version including references to LIBFT
# $(NAME): $(OBJ) $(HEADERS) $(MLX) $(LIBFT)
# 	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

#  without LIBFT - to be deleted once LIBFT is in place
$(NAME): $(OBJ) $(HEADERS) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(MLX) $(MLX_FLAGS) -o $(NAME) 

obj/%.o: src/%.c $(HEADERS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf obj
# @rm -rf $(MLX_DIR)/build
# $(MAKE) fclean -C $(LIBFT_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re