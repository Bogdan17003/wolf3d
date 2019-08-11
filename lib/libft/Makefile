# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:40:56 by bdeomin           #+#    #+#              #
#    Updated: 2019/08/05 19:20:03 by bdeomin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRC_DIR			= ./src/
OBJ_DIR			= ./obj/
LIB_DIR			= ./lib/
SRC_INC_DIR 	= ./inc/

C_FILES			=	ft_atoi.c \
					ft_bzero.c \
					ft_foundchar.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_lstadd.c \
					ft_lstaddend.c \
					ft_lstdel.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlen.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putchar.c \
					ft_putendl_fd.c \
					ft_putendl.c \
					ft_putnbr_fd.c \
					ft_putnbr.c \
					ft_putstr_fd.c \
					ft_putstr.c \
					ft_sortbubble.c \
					ft_strcat.c \
					ft_strchr.c \
					ft_strclr.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strjoinfree.c \
					ft_strjoinlen.c \
					ft_strjoinlenfree.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtrim.c \
					ft_tolower.c \
					ft_toupper.c \
					get_next_line.c



O_FILES 		= $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

FLAGS			= -g -Wall -Wextra -Werror
HEADER_FLAGS	= -I $(SRC_INC_DIR)

all:			$(NAME)

$(NAME):		$(O_FILES)
			ar rc $(NAME) $(O_FILES)
			ranlib $(NAME)

$(O_FILES):		| $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)
clean:
			rm -rf $(OBJ_DIR)
fclean:	clean
			rm -f $(NAME)
re: 	fclean all
