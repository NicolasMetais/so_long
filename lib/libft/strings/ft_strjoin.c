/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:56:31 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:46:03 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	j;
	char	*str;
	int		size;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * ((int)ft_strlen(s1) + (int)ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	size = ft_strlen(s1);
	i = -1;
	while (i++ < size)
		str[i] = s1[i];
	j = 0;
	while (i < size + (int)ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
/*
int main(void)
{
 	char *s1 = "my favorite animal is";
 	char *s2 = " ";
 	char *s3 = "the nyancat";
 	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
	
 	if (!strcmp(res, "my favorite animal is the nyancat"))
 		printf("PASS");
	else
	{
 		printf("ERROR");
	}
	free (res);
}*/
