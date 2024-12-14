/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:49 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/12 01:58:20 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_on_bg(t_img *bg, size_t y, size_t x, int color)
{
	char	*change_pix;

	if (color == (int)0x00FF00)
		return ;
	change_pix = bg->addr + (y * bg->line_len + x * (bg->bpp / 8));
	*(unsigned int *) change_pix = color;
}

unsigned int	get_img_pxl(t_img *stickonbg, size_t x, size_t y)
{
	return (*(unsigned int *)(stickonbg->addr
		+ (y * stickonbg->line_len + x * (stickonbg->bpp / 8))));
}

void	transparency(t_img *bg, t_img *stickonbg)
{
	size_t	i;
	size_t	j;

	i = 0;
	bg->addr = mlx_get_data_addr(bg->img, &(bg->bpp),
			&(bg->line_len), &(bg->endian));
	stickonbg->addr = mlx_get_data_addr(stickonbg->img, &(stickonbg->bpp),
			&(stickonbg->line_len), &(stickonbg->endian));
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			put_on_bg(bg, i, j, get_img_pxl(stickonbg, j, i));
			j++;
		}
		i++;
	}
}

int	coin_transparency(t_game *game,	int width, int len)
{
	game->coini.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->collect_img.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Coin.xpm", &width, &len);
	if (!game->coini.img || !game->collect_img.img)
		return (1);
	transparency(&game->coini, &game->collect_img);
	return (0);
}

int	player_transparency(t_game *game, int width, int len)
{
	game->playeri.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Ground.xpm", &width, &len);
	game->player->player_img.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/RedDino.xpm", &width, &len);
	if (!game->playeri.img || !game->player->player_img.img)
		return (1);
	transparency(&game->playeri, &game->player->player_img);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Exit.xpm", &width, &len);
	game->pstair.img = mlx_xpm_file_to_image(game->mlx,
			"GameSprites/Exit.xpm", &width, &len);
	if (!game->exit.img || !game->pstair.img)
		return (1);
	transparency(&game->pstair, &game->player->player_img);
	return (0);
}
