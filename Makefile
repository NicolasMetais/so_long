SRCS = 	src/so_long.c \
		src/error_manager.c \
		src/map_parse.c \
		src/gameboard.c \
		src/pathfinding.c \
		src/bfs.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = ./lib/libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make --silent -C ./lib/libft

clean:
	rm -rf *.o
	rm -rf ./src/*.o
	make clean -C ./lib/libft

c:
	cc ./src/map_parse.c ./src/bfs.c ./src/gameboard.c ./src/pathfinding.c ./src/so_long.c ./src/error_manager.c ./lib/libft/strings/ft_strlen.c ./lib/libft/strings/ft_strnstr.c ./lib/libft/strings/ft_strncmp.c ./lib/libft/get_next_line/src/get_next_line.c ./lib/libft/get_next_line/src/get_next_line_utils.c ./lib/libft/strings/ft_strjoin.c ./lib/libft/strings/ft_strchr.c ./lib/libft/strings/ft_substr.c ./lib/libft/mem/ft_calloc.c -g3

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./lib/libft

re:	fclean all

.PHONY: all compil clean fclean re