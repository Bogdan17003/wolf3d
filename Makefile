# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 14:32:03 by bdeomin           #+#    #+#              #
#    Updated: 2019/07/24 18:10:15 by bdeomin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= wolf3d

SRC_DIR			= ./src/
OBJ_DIR			= ./obj/
LIB_DIR			= ./lib/

SRC_INC_DIR 	= $(SRC_DIR)

C_FILES			= additional_f.c check_file.c draw.c gameplay.c hook.c \
					initialization.c main.c memory.c move_and_rotate.c \
					read_file.c textures.c

O_FILES 		= $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

LIBFT_DIR		= $(LIB_DIR)libft/
LIBFT_INC_DIR 	= $(LIBFT_DIR)
LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_FLAGS		= -lft -L $(LIBFT_DIR)

MINILIBX_DIR	= /usr/local/lib
MINILIBX_INC_DIR= /usr/local/include
MINILIBX_FLAGS	= -L $(MINILIBX_DIR) -lmlx -framework OpenCL -framework OpenGL -framework APPKit

FLAGS			= -g -Wall -Wextra -Werror
HEADER_FLAGS	= -I $(SRC_INC_DIR) -I $(LIBFT_INC_DIR) -I $(MINILIBX_INC_DIR)
LINK_FLAGS		= $(LIBFT_FLAGS) $(MINILIBX_FLAGS)


all:			$(NAME)

$(NAME):		$(LIBFT) $(O_FILES)
	gcc $(O_FILES) $(LINK_FLAGS) -o $(NAME)

$(O_FILES):		| $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean:			clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
