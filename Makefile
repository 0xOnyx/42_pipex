# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 18:45:16 by jerdos-s          #+#    #+#              #
#    Updated: 2022/10/18 18:45:17 by jerdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = libft
CFLAGS = 
CC = gcc
SRC_PATH = ./src/
OPTIONS = -Ilibft -Iincludes  -g3 -fsanitize=address
SRC =	ft_child_process.c \
		ft_init_env.c \
		ft_init_file.c \
		ft_init_fork.c \
		ft_init_pipe.c \
		main.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) $(OPTIONS) -c $(<) -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CLFAGS) $(OBJS) -L./libft -lft $(OPTIONS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: re fclean clean all $(LIBFT)
