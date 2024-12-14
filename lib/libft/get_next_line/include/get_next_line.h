/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:25:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/14 23:55:15 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*gt_next_line(int fd);
char	*gt_substr(char const *s, unsigned int start, size_t len);
size_t	gt_strlen(const char *s);
char	*gt_strchr(const char *s, int c);
char	*gt_strjoin( char *s1, char*s2);

#endif