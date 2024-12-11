/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_transparency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:49 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/11 00:19:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_on_bg(t_collect_img *coin, size_t y, size_t x, int color)
{
	char	*change_pix;

	if (color == (int)0x00FF00)
		return ;
	change_pix = coin->iaddr + (y * coin->iline_len + x * (coin->ibpp / 8));
	*(unsigned int *) change_pix = color;
}

unsigned int	get_img_pxl(t_collect_img *coin, size_t x, size_t y)
{
	return (*(unsigned int *)(coin->caddr
		+ (y * coin->cline_len + x * (coin->cbpp / 8))));
}

void	coin_transparency(t_collect_img *coin)
{
	size_t	i;
	size_t	j;

	i = 0;
	coin->iaddr = mlx_get_data_addr(coin->img, &(coin->ibpp),
			&(coin->iline_len), &(coin->iendian));
	coin->caddr = mlx_get_data_addr(coin->coin, &(coin->cbpp),
			&(coin->cline_len), &(coin->cendian));
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			put_on_bg(coin, i, j, get_img_pxl(coin, j, i));
			j++;
		}
		i++;
	}
}

