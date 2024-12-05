/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:29:37 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/03 00:43:01 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	setupcollector(char **gameboard, t_param *checker)
{
	int		i;
	size_t	j;

	i = -1;
	while (i++, gameboard[i])
	{
		j = 0;
		while (gameboard[i][j])
		{
			if (gameboard[i][j] != '\n')
			{
				if (gameboard[i][j] != '0' && gameboard[i][j] != '1' &&
					gameboard[i][j] != 'C' && gameboard[i][j] != 'E' &&
					gameboard[i][j] != 'P')
					checker->invalidchar = 1;
			}
			if (gameboard[i][j] == 'C')
				checker->collect += 1;
			if (gameboard[i][j] == 'E')
				checker->exit += 1;
			if (gameboard[i][j] == 'P')
				checker->spawn += 1;
			j++;
		}
	}
}

void	rectangle_check(char **gameboard, t_param *checker)
{
	size_t	i;
	size_t	j;
	size_t	maxsize;

	i = 0;
	while (gameboard[i])
	{
		j = 0;
		while (gameboard[i][j] && gameboard[i][j] != '\n')
			j++;
		if (i == 0)
			maxsize = j;
		if (maxsize != j)
		{
			checker->rectangle = 1;
			return ;
		}
		i++;
	}
	if (j == i)
		checker->rectangle = 2;
	checker->lenght = j;
}

void	wall_check(char **gameboard, t_param *checker)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (gameboard[i])
	{
		j = 0;
		while (gameboard[i][j])
		{
			if (gameboard[i][j] != '\n')
			{
				if ((gameboard[0][j] != '1' && gameboard[0][j] != 'E') ||
					(gameboard[checker->width - 1][j] != '1' &&
					gameboard[checker->width - 1][j] != 'E'))
					checker->wall = 1;
				if ((gameboard[i][0] != '1' && gameboard[i][0] != 'E') ||
					(gameboard[i][checker->lenght - 1] != '1' &&
					gameboard[i][checker->lenght - 1] != 'E'))
					checker->wall = 1;
			}
			j++;
		}
		i++;
	}	
}

size_t	map_check(char **gameboard, t_param *checker)
{
	rectangle_check(gameboard, checker);
	if (checker->rectangle != 0)
		write(2, "error", 5);
	setupcollector(gameboard, checker);
	wall_check(gameboard, checker);
	if (checker->exit != 1 || checker->invalidchar == 1
		|| checker->spawn != 1 || checker->collect < 1)
		write(2, "invalid map\n", 11);
	printf("\nlen: %zu\n", checker->lenght);
	printf("\nwidth: %zu\n", checker->width);
	printf("\ninvalidchar%zu\n", checker->invalidchar);
	printf("collect%zu\n", checker->collect);
	printf("exit%zu\n", checker->exit);
	printf("spawn%zu\n", checker->spawn);
	printf("rectangle%zu\n", checker->rectangle);
	printf("wall%zu\n", checker->wall);
	pathfinding(gameboard, checker);
	return (0);
}
