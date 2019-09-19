# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/13 15:55:07 by mwaterso     #+#   ##    ##    #+#        #
#    Updated: 2019/09/19 16:16:07 by mwaterso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol
FILE =  fct.c \
		fractol.c \
		hook.c \
		fractales.c
OBJ = $(FILE:%.c=%.o)
LIBFT = libft/libft.a
MLX = minilibx_macos/libmlx.a
CC = gcc
CFLAGS = -Wextra -Wall -Werror -o3

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft
		make -C minilibx_macos
		$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)
		make clean -C libft/

fclean: clean
		rm -f $(NAME)
		make fclean -C libft/

re: fclean all