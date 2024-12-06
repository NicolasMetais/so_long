/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:07:13 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/06 16:40:36 by nmetais          ###   ########.fr       */
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
		printf("\ny pos :%zu\n x pos :%zu\n", checkpoint->y, checkpoint->x);
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
