/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_charac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:00:42 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:50:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_floor_up(t_map smaller, t_game *game);
void	update_floor_down(t_map smaller, t_game *game);
void	update_floor_left(t_map smaller, t_game *game);
void	update_floor_right(t_map smaller, t_game *game);
void	handle_destroy(t_game *game);

void	move_up(t_game *game)
{
	t_map	smaller;

	smaller = game->map[game->player->pos->y][game->player->pos->x];
	if (smaller.up->type == '1')
		return ;
	if (smaller.up->type == 'E' && game->cmax == game->countcoin)
		handle_destroy(game);
	if (smaller.up->type == 'C')
	{
		game->countcoin++;
		smaller.up->type = '0';
	}
	if (game->countmove == 2147483647)
		game->countmove = 0;
	game->countmove++;
	ft_putnbr_fd(game->countmove, 1);
	ft_putchar_fd('\n', 1);
	update_floor_up(smaller, game);
	game->player->pos->x = smaller.up->pos.x;
	game->player->pos->y = smaller.up->pos.y;
}

void	move_down(t_game *game)
{
	t_map	smaller;

	smaller = game->map[game->player->pos->y][game->player->pos->x];
	if (smaller.down->type == '1')
		return ;
	if (smaller.down->type == 'E' && game->cmax == game->countcoin)
		handle_destroy(game);
	if (smaller.down->type == 'C')
	{
		game->countcoin++;
		smaller.down->type = '0';
	}
	if (game->countmove == 2147483647)
		game->countmove = 0;
	game->countmove++;
	ft_putnbr_fd(game->countmove, 1);
	ft_putchar_fd('\n', 1);
	update_floor_down(smaller, game);
	game->player->pos->x = smaller.down->pos.x;
	game->player->pos->y = smaller.down->pos.y;
}

void	move_left(t_game *game)
{
	t_map	smaller;

	smaller = game->map[game->player->pos->y][game->player->pos->x];
	if (smaller.left->type == '1')
		return ;
	if (smaller.left->type == 'E' && game->cmax == game->countcoin)
		handle_destroy(game);
	if (smaller.left->type == 'C')
	{
		game->countcoin++;
		smaller.left->type = '0';
	}
	if (game->countmove == 2147483647)
		game->countmove = 0;
	game->countmove++;
	ft_putnbr_fd(game->countmove, 1);
	ft_putchar_fd('\n', 1);
	update_floor_left(smaller, game);
	game->player->pos->x = smaller.left->pos.x;
	game->player->pos->y = smaller.left->pos.y;
}

void	move_right(t_game *game)
{
	t_map	smaller;

	smaller = game->map[game->player->pos->y][game->player->pos->x];
	if (smaller.right->type == '1')
		return ;
	if (smaller.right->type == 'E' && game->cmax == game->countcoin)
		handle_destroy(game);
	if (smaller.right->type == 'C')
	{
		game->countcoin++;
		smaller.right->type = '0';
	}
	if (game->countmove == 2147483647)
		game->countmove = 0;
	game->countmove++;
	ft_putnbr_fd(game->countmove, 1);
	ft_putchar_fd('\n', 1);
	update_floor_right(smaller, game);
	game->player->pos->x = smaller.right->pos.x;
	game->player->pos->y = smaller.right->pos.y;
}
