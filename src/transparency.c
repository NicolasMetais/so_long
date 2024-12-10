/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:49 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/10 18:38:01 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_on_bg(t_ground_img *ground, size_t y, size_t x, int color)
{
	char	*change_pix;

	if (color == (int)0x00FF00)
		return ;
	change_pix = ground->addr + (y * ground->line_len + x * (ground->bpp / 8));
	*(unsigned int *) change_pix = color;
}

unsigned int	get_img_pxl(t_collect_img *coin, size_t x, size_t y)
{
	return (*(unsigned int *)(coin->addr
		+ (y * coin->line_len + x * (coin->bpp / 8))));
}

void	coin_transparency(t_ground_img *ground, t_collect_img *coin,
		size_t y, size_t x)
{
	size_t	i;
	size_t	j;

	i = 0;
	ground->addr = mlx_get_data_addr(ground->ground_img, &(ground->bpp),
			&(ground->line_len), &(ground->endian));
	coin->addr = mlx_get_data_addr(coin->Cregular_img, &(coin->bpp),
			&(coin->line_len), &(coin->endian));
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			put_on_bg(ground, y + i, x + j, get_img_pxl(coin, i, j));
			j++;
		}
		i++;
	}
}

