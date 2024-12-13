/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:42:31 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/13 19:12:55 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>

size_t	gettablesize(char *arg)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open(arg, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	free(line);
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	**table_construct(char **gameboard, char *arg, t_param *checker)
{
	int		fd;
	size_t	i;

	i = 0;
	checker->width = gettablesize(arg);
	if (!checker->width)
		return (NULL);
	gameboard = malloc(sizeof(char *) * (checker->width + 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1 || !gameboard)
		return (free(gameboard), NULL);
	gameboard[i] = get_next_line(fd);
	if (!gameboard[i])
		return (freechar(gameboard), NULL);
	i++;
	while (i < checker->width)
	{
		gameboard[i] = get_next_line(fd);
		if (!gameboard[i])
			return (freechar(gameboard), NULL);
		i++;
	}
	gameboard[i] = NULL;
	close(fd);
	return (gameboard);
}
