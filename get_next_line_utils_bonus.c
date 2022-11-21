/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:39:20 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/20 16:39:21 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str2;

	str2 = s;
	while (n > 0)
	{
		str2[n - 1] = '\0';
		n--;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*array;

	array = malloc(nitems * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nitems * size);
	return (array);
}

char	*ft_alt_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	count;
	char	*joined;

	count = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	while (s1[count] != '\0')
	{
		joined[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		joined[len_s1 + count] = s2[count];
		count++;
	}
	joined[len_s1 + count] = '\0';
	free(s1);
	return (joined);
}

char	*ft_alt_strdup(char *s2, const char *string, size_t size)
{
	size_t	len_string;
	size_t	count;
	char	*array;

	free(s2);
	len_string = ft_strlen(string);
	if (len_string > size)
		len_string = size;
	count = 0;
	array = (char *) malloc((len_string + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (string[count] != '\0' && count < size - 1)
	{
		array[count] = string[count];
		count++;
	}
	array[count] = '\0';
	return (array);
}
