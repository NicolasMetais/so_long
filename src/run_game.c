/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:26 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/10 04:33:27 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	**map_gen(char **gameboard, t_param *checker);

int	handle_keypress(int keysym, t_game *game)
{
	int count;

	count = 0;
	if (keysym == XK_Escape)
		mlx_destroy_window(game->mlx, game->win);
	count++;
	printf("futur compteur tqt: %d\n", count);
	return (0);
}

int	handle_no_event(void *data)
{
	data = NULL;
	return (0);
}

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
	game.win = mlx_new_window(game.mlx, 1920, 1080, "So_long");
	build_map(&game, checker, gameboard);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_loop_hook(game.mlx, &handle_no_event, &game);
	mlx_loop(game.mlx);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
