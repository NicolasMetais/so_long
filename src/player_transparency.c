/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_transparency.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:09:26 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/11 13:52:15 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_on_gd(t_player *player, size_t y, size_t x, int color)
{
	char	*change_pix;

	if (color == (int)0x00FF00)
		return ;
	change_pix = player->iaddr + (y * player->iline_len + x * (player->ibpp / 8));
	*(unsigned int *) change_pix = color;
}

unsigned int	get_pl_pxl(t_player *player, size_t x, size_t y)
{
	return (*(unsigned int *)(player->paddr
		+ (y * player->pline_len + x * (player->pbpp / 8))));
}

void	player_transparency(t_player *player)
{
	size_t	i;
	size_t	j;

	i = 0;
	player->iaddr = mlx_get_data_addr(player->img, &(player->ibpp),
			&(player->iline_len), &(player->iendian));
	player->paddr = mlx_get_data_addr(player->player, &(player->pbpp),
			&(player->pline_len), &(player->pendian));
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			put_on_gd(player, i, j, get_pl_pxl(player, j, i));
			j++;
		}
		i++;
	}
}

