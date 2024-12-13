/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:26 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/13 02:56:05 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	**map_gen(char **gameboard, t_param *checker);
void	freetile(t_map **tile, size_t size);
void	freeimg(t_game *game);
void	freechar(char **table);
void	freeimg(t_game *game);

void	type_count(char **gameboard, t_param *checker)
{
	size_t	i;
	size_t	j;
	size_t	count_wall;
	size_t	count_ground;

	i = 0;
	count_wall = 0;
	count_ground = 0;
	while (i < checker->width)
	{
		j = 0;
		while (j < checker->lenght)
		{
			if (gameboard[i][j] == '0')
				count_ground++;
			if (gameboard[i][j] == '1')
				count_wall++;
		j++;
		}
	i++;
	}
	checker->groundcount = count_ground;
	checker->wallcount = count_wall;
}

void	run_game(char **gameboard, t_param *checker)
{
	t_game	game;

	type_count(gameboard, checker);
	game.map = map_gen(gameboard, checker);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 1080, "So_long");
	build_map(&game, checker, gameboard);
	freechar(gameboard);
	game.cmax = checker->collect;
	game_event(&game, checker);
	mlx_loop(game.mlx);

}
