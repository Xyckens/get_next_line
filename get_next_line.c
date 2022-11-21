/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:02:35 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/14 12:02:38 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	static char	*notready;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lido = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	byte = 1;
	while (ft_alt_strchr(lido) == -1 && byte > 0)
	{
		byte = read(fd, lido, BUFFER_SIZE);
		if (!lido || (byte <= 0 && !notready))
		{
			free(lido);
			return (NULL);
		}
		lido[byte] = '\0';
		notready = ft_alt_strjoin(notready, lido);
	}
	if (ft_alt_strchr(notready) > -1)
		lido = ft_alt_strdup(lido, notready, ft_alt_strchr(notready) + 2);
	else
		lido = ft_alt_strjoin(lido, notready);
	notready = backtoleft(notready, ft_alt_strchr(notready));
	return (lido);
}

/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("files/test.txt", O_RDONLY);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	close(fd);
}*/
/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	int		i = 0;
	fd = open("files/1-brouette.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	while (i < 80)
	{
		prt = get_next_line(fd);
		printf("%s", prt);
		free(prt);
		i++;
	}
	close(fd);
}*/
/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	int		i = 0;
	fd = open("files/42_no_nl", O_RDONLY);
	printf("fd = %d\n", fd);
	while (i < 1)
	{
		prt = get_next_line(fd);
		printf("%s", prt);
		free(prt);
		i++;
	}
	close(fd);
}*/