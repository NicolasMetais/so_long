/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:10:00 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:17:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Remplir une zone mémoire avec un octet donné */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cpoint;
	size_t	i;

	i = 0;
	cpoint = s;
	while (i < n)
	{
		cpoint[i] = c;
		i++;
	}
	return (cpoint);
}
