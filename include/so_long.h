/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:14:29 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/10 18:35:55 by nmetais          ###   ########.fr       */
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

typedef enum s_type
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	COLLECT = 'C',
	EXIT = 'E'
}	t_type;

typedef struct s_pos
{
	size_t	y;
	size_t	x;
}	t_pos;

typedef struct s_map
{
	t_type			type;
	t_pos			pos;
	struct s_map	*left;
	struct s_map	*right;
	struct s_map	*up;
	struct s_map	*down;
}				t_map;

typedef struct s_player
{
	t_map	*tile;
	void	*img;
}	t_player;

typedef struct s_collect_img
{
	void	*Cregular_img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_collect_img;

typedef struct s_wall_img
{
	void	*side_img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_wall_img;

typedef struct s_exit_img
{
	void	*img;
}	t_exit_img;

typedef struct s_ground_img
{
	void	*ground_img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_ground_img;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			**map;
	t_collect_img	*collect_img;
	t_wall_img		*wall_img;
	t_ground_img	*ground;
	t_player		*player;
	t_exit_img		*exit;
}	t_game;

void	run_game(char **gameboard, t_param *checker);
void	locatepos(t_locate *locate, size_t actualpos, size_t **pathtab,
			t_param *checker);
void	freecheckpoint(t_checkpoint *checkpoint);
void	freechar(char **table);
void	freesizet(size_t **table, size_t checker);
size_t	version_check(char *arg);
void	bfs(size_t **pathtab, t_param *checker,
			t_checkpoint *checkpoint);
void	build_map(t_game *game, t_param *checker, char **gameboard);
size_t	**dupboard(char **gameboard, t_param *checker);
char	**table_construct(char **gameboard, char *arg, t_param *checker);
size_t	map_check(char **gameboard, t_param *checker);
void	pathfinding(char **gameboard, t_param *checker);
void	isreachable(t_checkpoint *checkpoint, size_t *visited, size_t **pathtab,
			t_param *checker);

#endif