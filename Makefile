# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 12:17:01 by sdjeffal          #+#    #+#              #
#*   Updated: 2015/12/12 06:14:33 by sdjeffal         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang
CFLAG = -Wall -Werror -Wextra
CFRAMEWORK = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit


CPATH = srcs/
CFILES = \
	fdf.c \
	ft_countx.c \
	ft_getmaps.c \
	ft_initmlx.c\
	ft_traceligne.c \
	ft_initposition.c \
	ft_malloc.c \
	ft_init.c \
	ft_key_founct.c \

OPATH = obj/
OFILES = $(CFILES:.c=.o)
OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling \"$(NAME)\"..."
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME) $(CFRAMEWORK)
	@echo "Successful compilation!\n---"

$(OPATH)%.o: $(CPATH)%.c
	@mkdir -p $(OPATH)
	$(CC) $(CFLAGS) -I includes -c -o $@ $<

clean:
	@echo "Deleting the directory /obj..."
	make -C libft clean
	@rm -f $(OBJ)
	@echo "Deletion complete !"

fclean: clean
	@echo "Deleting binary "$(NAME)"..."
	make -C libft fclean
	@rm -f $(NAME)
	@echo "Deletion complete !"/

re: fclean all
