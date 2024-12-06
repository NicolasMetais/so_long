/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:01:40 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/06 18:19:42 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	spawnpos(char **gameboard, t_param *checker)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (gameboard[i])
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

void	checkpoint_extend(t_checkpoint *new, size_t c, t_param *checker,
	t_checkpoint *checkpoint)
{
	printf("%zu\n" ,checker->collect);
	printf("%zu\n", c);
	if (c < checker->collect)
	{
		printf("TEST\n");
		checkpoint->next = new;
		checkpoint = new;
		checkpoint->next = NULL;
	}
	else
		checkpoint->next = NULL;
}

void	getcheckpoints(char **gameboard, t_checkpoint *checkpoint,
		t_param *checker)
{
	size_t			i;
	size_t			j;
	size_t			c;
	t_checkpoint	*new;

	i = 0;
	c = 0;
	while (gameboard[i])
	{
		j = 0;
		while (gameboard[i][j])
		{
			if (gameboard[i][j] == 'C' || gameboard[i][j] == 'E')
			{
				checkpoint->x = j;
				checkpoint->y = i;
				new = malloc(sizeof(*new));
				printf("Y%zu\nX%zu\n", checkpoint->y,checkpoint->x);
				checkpoint_extend(new ,c, checker, checkpoint);
				c++;
			}
			j++;
		}
	i++;
	}
}

size_t	**dupboard(char **gameboard ,t_param *checker)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	**pathtab;

	i = 0;
	k = 0;
	pathtab = malloc(sizeof(size_t *) * (checker->width + 1));
	while (gameboard[i])
	{
		j = 0;
		pathtab[i] = malloc(sizeof(size_t) * (checker->lenght + 1));
		while (j < checker->lenght)
		{
			if (gameboard[i][j] == '1')
				pathtab[i][j] = 9999;
			else
				pathtab[i][j] = k++;
			j++;
		}
		pathtab[i][j] = 0;
		i++;
	}
	gameboard[i] = 0;
	return (pathtab);
}

void	pathfinding(char **gameboard, t_param *checker)
{
	t_checkpoint	*checkpoint;
	size_t			**pathtab;

	checkpoint = malloc(sizeof(checkpoint));
	spawnpos(gameboard, checker);
	getcheckpoints(gameboard, checkpoint, checker);
	while (checkpoint)
	{
		printf("\ny pos :%zu\n x pos :%zu\n", checkpoint->y, checkpoint->x);
		checkpoint = checkpoint->next;
	}
	pathtab = dupboard(gameboard, checker);
	pathfinder(pathtab, checker, checkpoint);
}
