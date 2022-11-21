/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:39:04 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/20 16:39:06 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_alt_strjoin(char *s1, char *s2);
char	*ft_alt_strdup(char *s2, const char *string, size_t size);
void	*ft_calloc(size_t nitems, size_t size);

#endif 
