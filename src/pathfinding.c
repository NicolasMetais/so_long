/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:01:40 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/12 01:58:56 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	spawnpos(char **gameboard, t_param *checker)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < checker->width)
	{
		j = 0;
		while (gameboard[i][j])
		{
			if (gameboard[i][j] == 'P')
			{
				checker->spawnx = j;
				checker->spawny = i;
			}
			j++;
		}
	i++;
	}
}

void	checkpoint_extend(t_checkpoint *new, size_t c, t_param *checker
	, t_checkpoint **checkpoint)
{
	if (c < checker->collect)
	{
		new = malloc(sizeof(*new));
		if (!new)
			return ;
		(*checkpoint)->next = new;
		*checkpoint = new;
	}
	else
		(*checkpoint)->next = NULL;
}

void	getcheckpoints(char **gameboard, t_checkpoint *checkpoint,
		t_param *checker)
{
	size_t			i;
	size_t			j;
	t_checkpoint	*new;
	size_t			c;

	i = 0;
	c = 0;
	new = NULL;
	while (i < checker->width)
	{
		j = 0;
		while (gameboard[i][j])
		{
			if (gameboard[i][j] == 'C' || gameboard[i][j] == 'E')
			{
				checkpoint->x = j;
				checkpoint->y = i;
				checkpoint_extend(new, c, checker, &checkpoint);
				c++;
			}
			j++;
		}
	i++;
	}
}

void	pathfinding(char **gameboard, t_param *checker)
{
	t_checkpoint	*checkpoint;
	size_t			**pathtab;

	checkpoint = malloc(sizeof(*checkpoint));
	if (!checkpoint)
		return ;
	spawnpos(gameboard, checker);
	getcheckpoints(gameboard, checkpoint, checker);
	pathtab = dupboard(gameboard, checker);
	if (!pathtab)
		return ;
	bfs(pathtab, checker, checkpoint);
	freesizet(pathtab, checker->width);
	freecheckpoint(checkpoint);
}
