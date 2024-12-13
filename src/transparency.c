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

#include "../include/so_long.h"

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
