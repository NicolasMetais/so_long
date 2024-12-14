/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_extend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:21:01 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:50:58 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	extend_dupboard(char *gameboard, size_t *pathtab, size_t k
	, t_param *checker)
{
	size_t	j;

	j = 0;
	while (j < checker->lenght)
	{
		if (gameboard[j] == '1')
			pathtab[j] = 9999;
		else
			pathtab[j] = k++;
		j++;
	}
	pathtab[j] = 0;
	return (k);
}

size_t	**dupboard(char **gameboard, t_param *checker)
{
	size_t	i;
	size_t	k;
	size_t	**pathtab;

	i = 0;
	k = 1;
	pathtab = malloc(sizeof(size_t *) * (checker->width + 1));
	if (!pathtab)
		return (free(pathtab), NULL);
	while (i < checker->width)
	{
		pathtab[i] = malloc(sizeof(size_t) * (checker->lenght + 1));
		if (!pathtab[i])
			return (freesizet(pathtab, checker->width), NULL);
		k = extend_dupboard(gameboard[i], pathtab[i], k, checker);
		i++;
	}
	gameboard[i] = 0;
	checker->walkable = k;
	return (pathtab);
}
