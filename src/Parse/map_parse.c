/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:29:37 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:51:10 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setupcollector(char **gameboard, t_param *checker)
{
	int		i;
	size_t	j;

	i = -1;
	while (i++, (size_t)i < checker->width)
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
	j = 0;
	while (gameboard[i])
	{
		j = 0;
		while (gameboard[i][j])
			j++;
		if (i == 0)
			maxsize = j;
		if (maxsize != j && !(checker->width - 1 == i && maxsize == j + 1))
		{
			checker->rectangle = 1;
			return ;
		}
		i++;
	}
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
				if (gameboard[0][j] != '1' ||
				gameboard[checker->width - 1][j] != '1')
					checker->wall = 1;
				if (gameboard[i][0] != '1' ||
				gameboard[i][checker->lenght - 1] != '1')
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
		return (write(2, "Error\n wrong map size", 22));
	if (checker->lenght * checker->width > 1920)
		return (write(2, "Error\n map will be rendered outside screen", 43));
	setupcollector(gameboard, checker);
	if (checker->invalidchar == 1)
		return (write(2, "Error \ninvalid char\n", 21));
	wall_check(gameboard, checker);
	if (checker->wall == 1)
		return (write(2, "Error \n Map should be surrounded by walls", 42));
	if (checker->exit > 1)
		return (write(2, "Error \nToo many exits", 22));
	if (checker->exit < 1)
		return (write(2, "Error \n No exit, dude i need to get out", 40));
	if (checker->spawn > 1)
		return (write(2, "Error \nToo many spawns", 23));
	if (checker->spawn < 1)
		return (write(2, "Error \nNo spawn", 16));
	if (checker->collect < 1)
		return (write(2, "Error \n At least one item please", 33));
	pathfinding(gameboard, checker);
	if (checker->path == 1)
		return (write(2, "Error \n No pathing possible. BFS aproved", 41));
	return (1);
}
