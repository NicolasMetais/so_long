/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:57:09 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:51:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeimg(t_game *game)
{
	if (game->wall_img.img)
		mlx_destroy_image(game->mlx, game->wall_img.img);
	if (game->ground.img)
		mlx_destroy_image(game->mlx, game->ground.img);
	if (game->collect_img.img)
		mlx_destroy_image(game->mlx, game->collect_img.img);
	if (game->coini.img)
		mlx_destroy_image(game->mlx, game->coini.img);
	if (game->playeri.img)
		mlx_destroy_image(game->mlx, game->playeri.img);
	if (game->player->player_img.img)
		mlx_destroy_image(game->mlx, game->player->player_img.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->pstair.img)
		mlx_destroy_image(game->mlx, game->pstair.img);
}

void	insert_map_img(t_game *game, size_t x, size_t y, char **gameboard)
{
	char	type;

	type = gameboard[y][x];
	if (type == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->ground.img, x * 32, y * 32);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img.img, x * 32, y * 32);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, x * 32, y * 32);
	else if (type == 'P')
	{
		game->player->pos->x = x;
		game->player->pos->y = y;
		mlx_put_image_to_window(game->mlx, game->win,
			game->playeri.img, x * 32, y * 32);
	}
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->coini.img, x * 32, y * 32);
}

int	open_img(t_game *game)
{
	int		failer;
	int		width;
	int		len;

	width = 32;
	len = 32;
	game->wall_img.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Wall.xpm", &width, &len);
	game->ground.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	if (!game->wall_img.img || !game->ground.img)
		return (1);
	failer = coin_transparency(game, width, len);
	if (failer == 1)
		return (1);
	failer = player_transparency(game, width, len);
	if (failer == 1)
		return (1);
	return (0);
}

// void	zoom(t_game *game, void *img, int x, int y)
// {
// 	int		zoom;
// 	void	*new_img;
// 	int		*zoom_data;
// 	int		*data;
// 	int		i;
// 	int		j;
// 	int		sizeW;
// 	int		sizeL;
// 	int 	orig_x;
// 	int		orig_y;

// 	zoom = 16 * 4;
// 	sizeW = 16;
// 	sizeL = 16;
// 	new_img = mlx_new_image(game->mlx, zoom, zoom);
// 	zoom_data = (int *)mlx_get_data_addr(new_img, &sizeW, &sizeL, &i);
// 	data = (int *)mlx_get_data_addr(img, &sizeW, &sizeL, &i);
// 	i = 0;
// 	while (i < zoom)
// 	{
// 		j = 0;
// 		while (j < zoom)
// 		{
// 			orig_x = (i / 4);
// 			orig_x = (j / 4);
// 			zoom_data[i * zoom + j] = data[orig_y * 16 + orig_x];
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_put_image_to_window(game->mlx, game->win, new_img, x, y);
// 	mlx_destroy_image(game->mlx, new_img);
// }

int	alloc_img(t_game *game)
{
	game->player = malloc (sizeof(t_player));
	if (!game->player)
		return (1);
	game->player->pos = malloc(sizeof(t_pos));
	if (!game->player->pos)
		return (1);
	game->player->player_img.img = NULL;
	return (0);
}

int	build_map(t_game *game, t_param *checker, char **gameboard)
{
	int	y;
	int	x;
	int	fail;

	fail = 0;
	fail = alloc_img(game);
	if (fail == 1)
		return (1);
	fail = open_img(game);
	if (fail == 1)
		return (1);
	y = 0;
	while (y < (int)checker->width)
	{
		x = 0;
		while (x <= (int)checker->lenght)
		{
			insert_map_img(game, x, y, gameboard);
			x++;
		}
		y++;
	}
	return (0);
}
