/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:26 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/13 19:41:22 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	**map_gen(char **gameboard, t_param *checker);
int		handle_destroy(t_game *game);
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

void	init_img(t_game *game)
{
	game->wall_img.img = NULL;
	game->ground.img = NULL;
	game->coini.img = NULL;
	game->collect_img.img = NULL;
	game->playeri.img = NULL;
	game->exit.img = NULL;
	game->pstair.img = NULL;
}


int	run_game(char **gameboard, t_param *checker)
{
	t_game	game;
	int		fail;

	init_img(&game);
	type_count(gameboard, checker);
	game.map = map_gen(gameboard, checker);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.win = mlx_new_window(game.mlx, 32 * checker->lenght,
			32 * checker->width, "So_long");
	if (!game.win)
		return (0);
	fail = build_map(&game, checker, gameboard);
	freechar(gameboard);
	if (!fail)
		handle_destroy(&game);
	game.cmax = checker->collect;
	game_event(&game, checker);
	mlx_loop(game.mlx);
	return (1);
}
