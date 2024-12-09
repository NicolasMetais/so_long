/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:07:13 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/08 18:55:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	freecheckpoint(t_checkpoint *checkpoint)
{
	t_checkpoint	*new;

	while (checkpoint)
	{
		new = checkpoint->next;
		free (checkpoint);
		checkpoint = new;
	}
}

void	locatepos(t_locate *locate, size_t actualpos, size_t **pathtab,
	t_param *checker)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (i < checker->width)
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

void	isreachable(t_checkpoint *checkpoint, size_t *visited, size_t **pathtab,
	t_param *checker)
{
	size_t	reach;
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (checkpoint)
	{
		reach = pathtab[checkpoint->y][checkpoint->x];
		i = 0;
		while (visited[i])
		{
			if (reach == visited[i])
				count++;
			i++;
		}
		checkpoint = checkpoint->next;
	}
	if (count != checker->collect + 1)
		checker->path = 1;
	free(visited);
}
