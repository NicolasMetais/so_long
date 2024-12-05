/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:42:31 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/02 16:15:12 by nmetais          ###   ########.fr       */
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
	free(line);
	i = 1;
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	return (i - 1);
}

char	**table_construct(char **gameboard, char *arg, t_param *checker)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	checker->width = gettablesize(arg);
	gameboard = malloc(checker->width * sizeof(char *) + 1);
	if (!gameboard)
		return (NULL);
	fd = open(arg, O_RDONLY);
	line = get_next_line(fd);
	gameboard[i] = line;
	i++;
	while (line)
	{
		line = get_next_line(fd);
		gameboard[i] = line;
		i++;
	}
	return (gameboard);
}
