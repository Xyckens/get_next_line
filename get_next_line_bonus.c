/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:38:48 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/20 16:38:51 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*backtoleft(char *s1, int offset)
{
	int		count;
	char	*array;

	count = 0;
	if (s1[offset + 1] == '\0' || offset == -1)
	{
		free(s1);
		return (NULL);
	}
	array = malloc((ft_strlen(s1) - offset + 1) * sizeof(char));
	while (s1[count + offset + 1] != '\0')
	{
		array[count] = s1[count + offset + 1];
		count++;
	}
	array[count] = '\0';
	free(s1);
	return (array);
}

int	ft_alt_strchr(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	ssize_t		byte;
	char		*lido;
	static char	*s1[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lido = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	byte = 1;
	while (ft_alt_strchr(lido) == -1 && byte > 0)
	{
		byte = read(fd, lido, BUFFER_SIZE);
		if (!lido || (byte <= 0 && !s1[fd]))
		{
			free(lido);
			return (NULL);
		}
		lido[byte] = '\0';
		s1[fd] = ft_alt_strjoin(s1[fd], lido);
	}
	if (ft_alt_strchr(s1[fd]) > -1)
		lido = ft_alt_strdup(lido, s1[fd], ft_alt_strchr(s1[fd]) + 2);
	else
		lido = ft_alt_strjoin(lido, s1[fd]);
	s1[fd] = backtoleft(s1[fd], ft_alt_strchr(s1[fd]));
	return (lido);
}
