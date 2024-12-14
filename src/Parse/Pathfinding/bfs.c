/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:39:10 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:50:55 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	visit(size_t pathtab, size_t *visited)
{
	size_t	i;
	size_t	bol;

	i = 0;
	bol = 0;
	while (visited[i])
	{
		if (visited[i] == pathtab)
			return (bol = 1);
		i++;
	}
	return (bol);
}
typedef struct s_neighbor {
	size_t	**queue;
	size_t	**visited;
	size_t	i;
	size_t	j;
}	t_neighbor;

void	valid_neigh(size_t valid_neighbor, t_neighbor *neighbor)
{
	if (valid_neighbor != 9999
		&& visit(valid_neighbor, *(neighbor->visited)) == 0)
	{
		(*(neighbor->queue))[neighbor->i] = valid_neighbor;
		(*(neighbor->visited))[neighbor->j] = valid_neighbor;
		neighbor->i++;
		neighbor->j++;
	}
}

void	process_queue(size_t **queue, size_t **pathtab, t_locate *locate,
		size_t **visited)
{
	t_neighbor	neighbor;

	neighbor.queue = queue;
	neighbor.visited = visited;
	neighbor.i = 0;
	neighbor.j = 0;
	while ((*queue)[neighbor.i] != 0)
		neighbor.i++;
	while ((*visited)[neighbor.j] != 0)
		neighbor.j++;
	valid_neigh(pathtab[locate->y - 1][locate->x], &neighbor);
	valid_neigh(pathtab[locate->y + 1][locate->x], &neighbor);
	valid_neigh(pathtab[locate->y][locate->x - 1], &neighbor);
	valid_neigh(pathtab[locate->y][locate->x + 1], &neighbor);
	neighbor.i = 0;
	while ((*queue)[neighbor.i] != 0)
	{
		(*queue)[neighbor.i] = (*queue)[neighbor.i + 1];
		neighbor.i++;
	}
}

void	bfs(size_t **pathtab, t_param *checker,
		t_checkpoint *checkpoint)
{
	size_t		*queue;
	size_t		*visited;
	size_t		actualpos;
	t_locate	*locate;

	queue = ft_calloc(sizeof(size_t), checker->walkable);
	if (!queue)
		return ;
	locate = malloc(sizeof(*locate));
	if (!locate)
		return ;
	visited = ft_calloc(sizeof(size_t), checker->walkable);
	if (!visited)
		return ;
	actualpos = pathtab[checker->spawny][checker->spawnx];
	queue[0] = actualpos;
	while (queue[0] != 0)
	{
		locatepos(locate, actualpos, pathtab, checker);
		process_queue(&queue, pathtab, locate, &visited);
		actualpos = queue[0];
	}
	free(locate);
	free(queue);
	isreachable(checkpoint, visited, pathtab, checker);
}
