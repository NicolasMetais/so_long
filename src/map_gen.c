/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:29:30 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/13 19:00:00 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	freetile(t_map **tile, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tile[i]);
		i++;
	}
	free(tile);
}

void	adjacent_tiles(t_map **tile, size_t y, size_t x, t_param *checker)
{
	if (x != 0)
		tile[y][x].left = &tile[y][x - 1];
	if (y != 0)
			tile[y][x].up = &tile[y - 1][x];
	if (y < checker->width - 1)
	{
		tile[y][x].down = &tile[y + 1][x];
	}
		tile[y][x].right = &tile[y][x + 1];
}

t_map	**allocmap(t_param *checker)
{
	t_map	**tile;
	size_t	i;

	i = 0;
	tile = malloc(sizeof(t_map *) * (checker->width));
	if (!tile)
		return (free(tile), NULL);
	while (i < checker->width)
	{
		tile[i] = malloc(sizeof(t_map) * (checker->lenght));
		if (!tile[i])
			return (freetile(tile, i), NULL);
		i++;
	}
	return (tile);
}

t_map	**map_gen(char **gameboard, t_param *checker)
{
	t_map	**tile;
	size_t	y;
	size_t	x;

	y = 0;
	tile = allocmap(checker);
	if (!tile)
		return (NULL);
	while (gameboard[y])
	{
		x = 0;
		while (x < checker->lenght)
		{
			tile[y][x].type = gameboard[y][x];
			tile[y][x].pos.y = y;
			tile[y][x].pos.x = x;
			adjacent_tiles(tile, y, x, checker);
			x++;
		}
		y++;
	}
	return (tile);
}
