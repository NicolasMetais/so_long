/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:26 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/09 05:14:27 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	data = NULL;
	return (0);
}


void	run_game(char **gameboard, t_param *checker)
{
	//void	*img;
	//int		width = 50;
	//int		height = 50;
	t_game	game;
	t_vars	vars;

	game.map = map_gen(game.map, gameboard, checker);
	vars.mlx = mlx_init();
	//img = mlx_xpm_file_to_image(mlx, "
	//./Character Part6/char 8. Character 8.png", &width, &height);
	vars.win = mlx_new_window(vars.mlx, 1000, 500, "So_long");
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
