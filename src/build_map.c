/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:57:09 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/13 19:48:26 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	transparency(t_img *bg, t_img *stickonbg);
void	player_transparency(t_player *player);

void	freeimg(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall_img.img);
	mlx_destroy_image(game->mlx, game->ground.img);
	mlx_destroy_image(game->mlx, game->collect_img.img);
	mlx_destroy_image(game->mlx, game->coini.img);
	mlx_destroy_image(game->mlx, game->playeri.img);
	mlx_destroy_image(game->mlx, game->player->player_img.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->pstair.img);
	free(game->player->pos);
	free(game->player);
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

void	open_img(t_game *game)
{
	int		width;
	int		len;

	width = 32;
	len = 32;
	game->wall_img.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Wall.xpm", &width, &len);
	game->ground.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->coini.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->collect_img.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Coin.xpm", &width, &len);
	transparency(&game->coini, &game->collect_img);
	game->playeri.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->player->player_img.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/RedDino.xpm", &width, &len);
	transparency(&game->playeri, &game->player->player_img);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Exit.xpm", &width, &len);
	game->pstair.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Exit.xpm", &width, &len);
	transparency(&game->pstair, &game->player->player_img);
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
		return (0);
	game->player->pos = malloc(sizeof(t_pos));
	if (!game->player->pos)
		return (0);
	game->player->player_img.img = NULL;
	return (1);
}

int	build_map(t_game *game, t_param *checker, char **gameboard)
{
	int	y;
	int	x;
	int	fail;

	fail = alloc_img(game);
	if (!game)
		return (0);
	open_img(game);
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
	return (1);
}
