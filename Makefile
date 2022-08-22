NAME = pipex
LIBFT = libft
CFLAGS = 
CC = gcc
SRC_PATH = ./src/
OPTIONS = -Ilibft -Iincludes  -L./libft -lft -g3 -fsanitize=address
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
	$(CC) $(CLFAGS) $(OBJS) $(OPTIONS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: flcean all

.PHONY: re fclean clean all $(LIBFT)