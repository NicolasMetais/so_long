/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 01:07:21 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:50:46 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_floor_up(t_map smaller, t_game *game)
{
	if (smaller.type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	if (smaller.up->type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pstair.img,
			smaller.up->pos.x * 32, smaller.up->pos.y * 32);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->playeri.img,
			smaller.up->pos.x * 32, smaller.up->pos.y * 32);
	}
}

void	update_floor_down(t_map smaller, t_game *game)
{
	if (smaller.type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	if (smaller.down->type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pstair.img,
			smaller.down->pos.x * 32, smaller.down->pos.y * 32);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->playeri.img,
			smaller.down->pos.x * 32, smaller.down->pos.y * 32);
	}
}

void	update_floor_left(t_map smaller, t_game *game)
{
	if (smaller.type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	if (smaller.left->type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pstair.img,
			smaller.left->pos.x * 32, smaller.left->pos.y * 32);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->playeri.img,
			smaller.left->pos.x * 32, smaller.left->pos.y * 32);
	}
}

void	update_floor_right(t_map smaller, t_game *game)
{
	if (smaller.type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->player->pos->x * 32, game->player->pos->y * 32);
	if (smaller.right->type == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pstair.img,
			smaller.right->pos.x * 32, smaller.right->pos.y * 32);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->playeri.img,
			smaller.right->pos.x * 32, smaller.right->pos.y * 32);
	}
}
