/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:14:29 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/13 19:29:00 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_param
{
	size_t	rectangle;
	size_t	invalidchar;
	size_t	collect;
	size_t	exit;
	size_t	wall;
	size_t	path;
	size_t	spawn;
	size_t	width;
	size_t	lenght;
	size_t	spawnx;
	size_t	spawny;
	size_t	walkable;
	size_t	groundcount;
	size_t	wallcount;
}	t_param;

typedef struct s_checkpoint
{
	size_t				x;
	size_t				y;
	struct s_checkpoint	*next;
}	t_checkpoint;

typedef struct s_locate
{
	size_t	x;
	size_t	y;
}	t_locate;

typedef struct s_pos
{
	size_t	y;
	size_t	x;
}	t_pos;

typedef struct s_map
{
	char			type;
	t_pos			pos;
	struct s_map	*left;
	struct s_map	*right;
	struct s_map	*up;
	struct s_map	*down;
}				t_map;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	t_map	*tile;
	t_pos	*pos;
	t_img	player_img;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			countmove;
	size_t		cmax;
	t_map		**map;
	t_img		collect_img;
	t_img		wall_img;
	t_player	*player;
	t_img		exit;
	t_img		playeri;
	size_t		countcoin;
	t_img		ground;
	t_img		coini;
	t_img		pstair;
	size_t		size;
}	t_game;

int		run_game(char **gameboard, t_param *checker);
void	locatepos(t_locate *locate, size_t actualpos, size_t **pathtab,
			t_param *checker);
void	freecheckpoint(t_checkpoint *checkpoint);
void	freechar(char **table);
void	freesizet(size_t **table, size_t checker);
size_t	version_check(char *arg);
void	bfs(size_t **pathtab, t_param *checker,
			t_checkpoint *checkpoint);
void	game_event(t_game *game, t_param *checker);
int		build_map(t_game *game, t_param *checker, char **gameboard);
size_t	**dupboard(char **gameboard, t_param *checker);
char	**table_construct(char **gameboard, char *arg, t_param *checker);
size_t	map_check(char **gameboard, t_param *checker);
void	pathfinding(char **gameboard, t_param *checker);
void	isreachable(t_checkpoint *checkpoint, size_t *visited, size_t **pathtab,
			t_param *checker);

#endif