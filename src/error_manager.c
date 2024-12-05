/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:43:10 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/03 00:43:35 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>

size_t	version_check(char *arg)
{
	char	*version;

	version = ft_strnstr(arg, ".ber", ft_strlen(arg));
	if (version != NULL)
		return (0);
	return (1);
}
