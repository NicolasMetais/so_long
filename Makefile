SRCS = 	src/so_long.c \
		src/gameboard.c \
		src/Parse/map_parse.c \
		src/Parse/Pathfinding/pathfinding.c \
		src/Parse/Pathfinding/pathfinding_extend.c \
		src/Parse/Pathfinding/bfs.c \
		src/Parse/Pathfinding/bfs_bis.c \
		src/Game/run_game.c \
		src/Game/map_gen.c \
		src/Game/game_event.c \
		src/Game/move_charac.c \
		src/Game/update_floor.c \
		src/Game/Images/build_map.c \
		src/Game/Images/transparency.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilib/libft/include -Iminilibx-linux -Iinclude

NAME = so_long

MLX_F = libmlx.a

LIB = ./lib/libft/libft.a

all: $(NAME)

lib:
	make -C ./lib/libft

mlx:
	make -C ./minilibx-linux

$(NAME): lib mlx $(OBJS)
	$(CC) $(OBJS) ./lib/libft/libft.a ./minilibx-linux/libmlx.a -lX11 -lXext -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf ./src/*.o
	rm -rf ./src/Game/*.o
	rm -rf ./src/Game/Images/*.o
	rm -rf ./src/Parse/*.o
	rm -rf ./src/Parse/Pathfinding/*.o
	make clean -C ./lib/libft
	make clean -C ./minilibx-linux/

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./lib/libft

re:	fclean all

.PHONY: all compil c lib mlx clean fclean re