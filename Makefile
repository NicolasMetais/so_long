SRCS = 	src/so_long.c \
		src/error_manager.c \
		src/map_parse.c \
		src/gameboard.c \
		src/pathfinding.c \
		src/pathfinding_extend.c \
		src/bfs.c \
		src/bfs_bis.c \
		src/run_game.c \
		src/map_gen.c \
		src/build_map.c \
		src/coin_transparency.c \
		src/player_transparency.c \
		src/game_event.c \
		src/move_charac.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = so_long

MLX_F = libmlx.a

LIB = ./lib/libft/libft.a

all: $(NAME)

lib:
	@make -C ./lib/libft

mlx:
	@make -C ./minilibx-linux

$(NAME): lib mlx $(OBJS)
	$(CC) $(OBJS) ./lib/libft/libft.a ./minilibx-linux/libmlx.a -lX11 -lXext -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf ./src/*.o
	make clean -C ./lib/libft
	make clean -C ./minilibx-linux/

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./lib/libft

re:	fclean all

.PHONY: all compil c lib mlx clean fclean re