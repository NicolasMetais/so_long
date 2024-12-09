/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:15:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/09 04:16:19 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h> // A DELETE
#include <fcntl.h>

void	freechar(char **table)
{
	size_t	i;

	i = 0;
	if (!table)
		return ;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	freesizet(size_t **table, size_t checker)
{
	size_t	i;

	i = 0;
	while (i < checker)
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
	size_t	error;

	file = "test.ber";
	init(&checker);
	gameboard = NULL;
	/*if (ac == 2)
	{*/
		if (version_check(file) == 1)
			return (write(2, "Error \n Bad file extension", 27));
		gameboard = table_construct(gameboard, file, &checker);
		error = map_check(gameboard, &checker);
		if (error != 1)
			return (freechar(gameboard), 1);
		run_game(gameboard, checker);
		freechar(gameboard);
		

	//}
}
