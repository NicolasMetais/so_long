/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:30 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/11 16:24:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keysym == XK_Up)
		move_up(game);
	if (keysym == XK_Down)
		move_down(game);
	if (keysym == XK_Left)
		move_left(game);
	if (keysym == XK_Right)
		move_right(game);
	return (0);
}

void	game_event(t_game *game, t_param *checker)
{
	game->countmove = 0;
	checker->invalidchar = 0;
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, game);
}