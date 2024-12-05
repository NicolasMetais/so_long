/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:39:10 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/05 01:29:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	locatepos(t_locate *locate, size_t actualpos, size_t **pathtab)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (pathtab[i])
	{
		j = 0;
		while (pathtab[i][j])
		{
			if (actualpos == pathtab[i][j])
			{
				locate->x = j;
				locate->y = i;
			}
			j++;
		}
	i++;
	}
}

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

void	process_queue(size_t **q, size_t **p, t_locate *l, size_t **v)
{
	size_t	i;

	i = 0;
	while ((*q)[i] != 0)
	{
		(*q)[i] = (*q)[i + 1];
		i++;
	}
	if (p[l->y - 1][l->x] != 9999 && visit(p[l->y - 1][l->x], *v) == 0)
	{
		(*q)[i++] = p[l->y - 1][l->x];
		printf("%zu\n", p[l->y - 1][l->x]);
	}
	if (p[l->y + 1][l->x] != 9999 && visit(p[l->y + 1][l->x], *v) == 0)
	{
		(*q)[i++] = p[l->y + 1][l->x];
		printf("%zu\n", p[l->y - 1][l->x]);
	}
	if (p[l->y][l->x - 1] != 9999 && visit(p[l->y][l->x - 1], *v) == 0)
	{
		(*q)[i++] = p[l->y][l->x - 1];
		printf("%zu\n", p[l->y][l->x - 1]);
	}
	if (p[l->y][l->x + 1] != 9999 && visit(p[l->y][l->x + 1], *v) == 0)
	{
		(*q)[i++] = p[l->y][l->x + 1];
		printf("%zu\n", p[l->y][l->x + 1]);
	}
	i = 0;
	while ((*q)[i] != 0)
	{
		printf("CA MARCHE%zu", (*q)[i]);
		i++;
	}
	i = 0;
	while ((*v)[i] != 0)
	i++;
	(*v)[i] = p[l->y][l->x];
}

size_t	pathfinder(size_t **pathtab, t_param *checker,
		t_checkpoint *checkpoint)
{
	size_t		*queue;
	size_t		*visited;
	size_t		actualpos;
	size_t		searched;
	t_locate	*locate;

	queue = calloc(sizeof(size_t), 250);
	locate = malloc(sizeof(*locate));
	visited = calloc(sizeof(size_t), 250);
	actualpos = pathtab[checker->spawny][checker->spawnx];
	searched = pathtab[checkpoint->y][checkpoint->x];
	queue[0] = actualpos;
	while (queue[0] != 0)
	{
		locatepos(locate, actualpos, pathtab);
		process_queue(&queue, pathtab, locate, &visited);
		actualpos = queue[0];
	}
	free(locate);
	free(queue); //free in isreachable
	free(visited);

	return (0/*isreachable(visited, searched)*/);
}

void	bfs_path(size_t **pathtab, t_param *checker,
		t_checkpoint *checkpoint)
{
	size_t	bol;

	bol = 0;
	while (checkpoint)
	{
		//printf("\nx:%zu\n", checkpoint->x);
		//printf("y:%zu\n", checkpoint->y);
		bol = pathfinder(pathtab, checker, checkpoint);
		if (bol == 1)
			write(1, "error", 5);
		checkpoint = checkpoint->next;
	}
}
