/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:52:47 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:54:19 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	gt_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gt_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (start >= gt_strlen(s))
		len = 0;
	else if (len > gt_strlen(s) - start)
		len = gt_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*gt_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	if (!s || !c)
		return (NULL);
	i = 0;
	d = (unsigned char) c;
	if (d == '\0')
		return ((char *)s + gt_strlen(s));
	while (s[i])
	{
		if (s[i] == d)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

char	*gt_strjoin( char *s1, char*s2)
{
	int		i;
	size_t	j;
	char	*str;
	int		size1;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * ((int)gt_strlen(s1) + (int)gt_strlen(s2) + 1));
	if (!str)
		return (NULL);
	size1 = gt_strlen(s1);
	i = -1;
	while (i++, i < size1)
		str[i] = s1[i];
	j = 0;
	while (i < size1 + (int)gt_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
