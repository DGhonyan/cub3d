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

SRCS =	src/main.c	src/drowutils.c	src/float_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

LIBFT = libft/libft.a

RM = rm -rf

ifeq ($(UNAME_S), Linux)
	CFLAGS = -Wall -Werror -Wextra -D LINUX
	LINKLIB = -L libft/ -lft -lm -L../mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	CFLAGS = -Wall -Werror -Wextra
	LINKLIB = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -lm
endif

all : $(NAME)

$(NAME) : $(OBJS) ${LIBFT}
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LINKLIB) -I./include
	@echo ""
	@echo "\033[1;32mcub3d Compiled\033[1;0m"

%.o : %.c ${LIBFT} Makefile ./include/cub3d.h
	$(CC) -c $(CFLAGS) -o $@ $<
	@echo -n "\033[1;35m♥\033[1;0m"

${LIBFT} : ./libft/Makefile ./libft/libft.h ./libft/*.c
	$(MAKE) all -C libft/
	@echo "\033[1;32mlibft Compiled\033[1;0m"

clean :
	@$(RM) $(OBJS)
	@echo "\033[1;31mcub3d Clean\033[1;0m"

fclean : clean
	@$(MAKE) fclean -C libft/
	@$(RM) $(NAME)
	@echo "\033[1;31mcub3d Fclean\033[1;0m"

re : fclean all

.PHONY : all clean fclean re