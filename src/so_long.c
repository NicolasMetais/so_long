/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:15:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/03 14:36:22 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h> // A DELETE
#include <fcntl.h>

void	freeme(char **table)
{
	size_t	i;

	i = 0;
	while (table)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	init(t_param *checker)
{
	checker->rectangle = 0;
	checker->invalidchar = 0;
	checker->collect = 0;
	checker->exit = 0;
	checker->wall = 0;
	checker->path = 0;
	checker->spawn = 0;
	checker->width = 0;
	checker->lenght = 0;
}

int	main(void)
{
	char	**gameboard;
	t_param	checker;
	char	*file;

	file = "test.ber";
	init(&checker);
	gameboard = NULL;
	/*if (ac == 2)
	{*/
		if (version_check(file) == 1)
			return (write(2, "error", 6));
		gameboard = table_construct(gameboard, file, &checker);
		if (map_check(gameboard, &checker) == 1)
			return (write(2, "wrong map", 9));
		else
			printf("GO\n");
		free (gameboard);
	//}
}
