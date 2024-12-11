/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:57:09 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/11 01:21:20 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	coin_transparency(t_collect_img *coin);
void	player_transparency(t_player *player);

void	insert_map_img(t_game *game, size_t x, size_t y, char **gameboard)
{
	char	type;

	type = gameboard[y][x];
	if (type == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->ground->img, x * 32, y * 32);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img->side_img, x * 32, y * 32);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit->img, x * 32, y * 32);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player->img, x * 32, y * 32);
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect_img->img, x * 32, y * 32);
}

void	open_img(t_game *game)
{
	int	width;
	int	len;

	width = 32;
	len = 32;
	game->wall_img->side_img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Wall.xpm", &width, &len);
	game->ground->img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->collect_img->img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->collect_img->coin = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Coin.xpm", &width, &len);
	coin_transparency(game->collect_img);
	game->player->img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->player->player = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/RedDino.xpm", &width, &len);
	player_transparency(game->player);
	game->exit->img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Exit.xpm", &width, &len);
	if (!game->wall_img->side_img || game->ground->img
		|| game->collect_img->img || game->player->img
		|| game->exit->img)
		return ;
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

void	build_map(t_game *game, t_param *checker, char **gameboard)
{
	size_t	y;
	size_t	x;

	game->wall_img = malloc (sizeof(t_wall_img) * checker->wallcount);
	game->ground = malloc (sizeof(t_ground_img) * checker->groundcount);
	game->collect_img = malloc (sizeof(t_collect_img) * checker->collect - 1);
	game->exit = malloc (sizeof(t_exit_img));
	game->player = malloc (sizeof(t_player));
	if (!game->exit || !game->collect_img || !game->ground || !game->wall_img)
		return ;
	open_img(game);
	y = 0;
	while (y < checker->width)
	{
		x = 0;
		while (x <= checker->lenght)
		{
			insert_map_img(game, x, y, gameboard);
			x++;
		}
		y++;
	}
}
