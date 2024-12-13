/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:30 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/13 17:59:02 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	freeimg(t_game *game);
void	freetile(t_map **tile, size_t size);

int	handle_destroy(t_game *game)
{
	freeimg(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	freetile(game->map, game->size);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		handle_destroy(game);
	if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
		move_up(game);
	if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
		move_down(game);
	if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
		move_left(game);
	if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
		move_right(game);
	return (0);
}

void	game_event(t_game *game, t_param *checker)
{
	game->countmove = 0;
	game->countcoin = 0;
	game->size = checker->width;
	checker->invalidchar = 0;
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask,
		&handle_destroy, game);
}
