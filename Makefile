# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 12:15:29 by mtiesha           #+#    #+#              #
#    Updated: 2022/09/11 12:15:29 by mtiesha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S = $(shell uname -s)

NAME =	cub3d

MLX_DIR = mlx_linux

CFLAGS = -g -Wall -Wextra -Iinclude -Imlx_linux -Ilibft

SRCS =	$(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

CC = cc

LIBFT = libft/libft.a

RM = rm -rf

ifeq ($(UNAME_S), Linux)
	CFLAGS += -D LINUX
	LINKLIB = -L libft/ -lft -lm -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else
	LINKLIB = -L libft/ -lft -framework OpenGL -framework AppKit -lm -lmlx
endif

all : mlx $(NAME)

mlx:
	make -C $(MLX_DIR)

$(NAME) : $(OBJS) ${LIBFT}
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LINKLIB)
	@echo ""
	@echo "\033[1;32mcub3d Compiled\033[1;0m"

%.o : %.c ${LIBFT} Makefile ./include/cub3d.h
	$(CC) -c $(CFLAGS) -o $@ $<
	@echo -n "\033[1;35m♥\033[1;0m"

${LIBFT} : ./libft/Makefile ./libft/libft.h ./libft/*.c
	$(MAKE) all -C libft/
	@echo "\033[1;32mlibft Compiled\033[1;0m"

clean :
	@$(RM) src/*.o
	@echo "\033[1;31mcub3d Clean\033[1;0m"

fclean : clean
	@$(MAKE) fclean -C libft/
	@$(RM) $(NAME)
	@echo "\033[1;31mcub3d Fclean\033[1;0m"

clean_mlx:
	make clean -C $(MLX_DIR)

re : fclean all

.PHONY : all clean fclean re mlx
