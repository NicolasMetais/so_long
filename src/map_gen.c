/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:29:30 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/11 16:12:54 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	adjacent_tiles(t_map **tile, size_t y, size_t x)
{
	if (x != 0)
		tile[y][x].left = &tile[y][x - 1];
	if (y != 0)
			tile[y][x].up = &tile[y - 1][x];
	if (tile[y + 1])
			tile[y][x].down = &tile[y + 1][x];
	tile[y][x].right = &tile[y][x + 1];
}

t_map	**allocmap(t_param *checker)
{
	t_map	**tile;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tile = malloc(sizeof(t_map *) * (checker->width + 1));
	if (!tile)
		return (free(tile), NULL);
	while (i < (int)checker->width)
	{
		tile[i] = malloc(sizeof(t_map) * checker->lenght);
		if (!tile[i])
		{
			while (i >= 0)
			{
				free(tile[i]);
				i--;
			}
		}
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
		return (write(1, "tile malloc fail", 17), NULL);
	while (y < checker->width)
	{
		x = 0;
		while (x < checker->lenght)
		{
			tile[y][x].type = gameboard[y][x];
			tile[y][x].pos.y = y;
			tile[y][x].pos.x = x;
			adjacent_tiles(tile, y, x);
			x++;
		}
		y++;
	}
	tile[y] = 0;
	return (tile);
}
