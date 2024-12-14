/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:15:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:51:25 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

size_t	version_check(char *arg)
{
	char	*version;

	version = ft_strnstr(arg, ".ber", ft_strlen(arg));
	if (version != NULL)
		return (0);
	return (1);
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
	checker->wallcount = 0;
	checker->groundcount = 0;
}

int	main(int ac, char **av)
{
	char	**gameboard;
	int		fail;
	t_param	checker;
	size_t	error;

	init(&checker);
	gameboard = NULL;
	if (ac == 2)
	{
		if (version_check(av[1]) == 1)
			return (write(2, "Error \n Bad file extension", 27));
		gameboard = table_construct(gameboard, av[1], &checker);
		if (!gameboard)
			return (0);
		error = map_check(gameboard, &checker);
		if (error != 1)
			return (freechar(gameboard), 1);
		fail = run_game(gameboard, &checker);
		freechar(gameboard);
		if (!fail)
			return (0);
	}
}
