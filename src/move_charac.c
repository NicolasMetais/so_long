/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_charac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:00:42 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/11 16:27:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player->pos->y][game->player->pos->x].up->type == '1')
		return ;
	if (game->map[game->player->pos->y][game->player->pos->x].up->type == 'C')
		printf("C");
	game->countmove++;	 //A PROTEGER DE L'OVERFLOW
	printf("%zu\n", game->countmove);
	mlx_put_image_to_window(game->mlx, game->win,
		game->ground->img, game->player->pos->x * 32,
		game->player->pos->y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player->img,
		game->map[game->player->pos->y]
	[game->player->pos->x].up->pos.x * 32,
		game->map[game->player->pos->y]
	[game->player->pos->x].up->pos.y * 32);
	game->player->pos->x = game->map[game->player->pos->y]
	[game->player->pos->x].up->pos.x;
	game->player->pos->y = game->map[game->player->pos->y]
	[game->player->pos->x].up->pos.y;
}

void	move_down(t_game *game)
{
	if (game->map[game->player->pos->y][game->player->pos->x].down->type == '1')
		return ;
	if (game->map[game->player->pos->y][game->player->pos->x].down->type == 'C')
		printf("C");
	game->countmove++;	 //A PROTEGER DE L'OVERFLOW
	printf("%zu\n", game->countmove);
	mlx_put_image_to_window(game->mlx, game->win,
		game->ground->img, game->player->pos->x * 32,
		game->player->pos->y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player->img,
		game->map[game->player->pos->y]
	[game->player->pos->x].down->pos.x * 32,
		game->map[game->player->pos->y]
	[game->player->pos->x].down->pos.y * 32);
	game->player->pos->x = game->map[game->player->pos->y]
	[game->player->pos->x].down->pos.x;
	game->player->pos->y = game->map[game->player->pos->y]
	[game->player->pos->x].down->pos.y;
}

void	move_left(t_game *game)
{
	if (game->map[game->player->pos->y][game->player->pos->x].left->type == '1')
		return ;
	if (game->map[game->player->pos->y][game->player->pos->x].left->type == 'C')
		printf("C");
	game->countmove++; 	 //A PROTEGER DE L'OVERFLOW
	printf("%zu\n", game->countmove);
	mlx_put_image_to_window(game->mlx, game->win,
		game->ground->img, game->player->pos->x * 32,
		game->player->pos->y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player->img,
		game->map[game->player->pos->y]
	[game->player->pos->x].left->pos.x * 32,
		game->map[game->player->pos->y]
	[game->player->pos->x].left->pos.y * 32);
	game->player->pos->x = game->map[game->player->pos->y]
	[game->player->pos->x].left->pos.x;
	game->player->pos->y = game->map[game->player->pos->y]
	[game->player->pos->x].left->pos.y;
}

void	move_right(t_game *game)
{
	if (game->map[game->player->pos->y][game->player->pos->x].right->type == '1')
		return ;
	if (game->map[game->player->pos->y][game->player->pos->x].right->type == 'C')
		printf("C");
	game->countmove++;	 //A PROTEGER DE L'OVERFLOW
	printf("%zu\n", game->countmove);
	mlx_put_image_to_window(game->mlx, game->win,
		game->ground->img, game->player->pos->x * 32,
		game->player->pos->y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player->img,
		game->map[game->player->pos->y]
	[game->player->pos->x].right->pos.x * 32,
		game->map[game->player->pos->y]
	[game->player->pos->x].right->pos.y * 32);
	game->player->pos->x = game->map[game->player->pos->y]
	[game->player->pos->x].right->pos.x;
	game->player->pos->y = game->map[game->player->pos->y]
	[game->player->pos->x].right->pos.y;
}


