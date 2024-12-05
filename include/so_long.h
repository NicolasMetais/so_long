/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:14:29 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/04 15:51:19 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"

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

void	bfs_path(size_t **pathtab,
			t_param *checker, t_checkpoint *checkpoint);
size_t	version_check(char *arg);
void	freeme(char **table);
char	**table_construct(char **gameboard, char *arg, t_param *checker);
size_t	map_check(char **gameboard, t_param *checker);
void	pathfinding(char **gameboard, t_param *checker);

#endif