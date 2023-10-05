/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:18:29 by mtiesha           #+#    #+#             */
/*   Updated: 2022/05/20 18:28:45 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	memory - mem cell to malloc
	fd - read from
*/

char	*get_next_line(int fd)
{
	char	*s;
	char	c;
	int		rd;

	s = NULL;
	rd = 0;
	c = '\0';
	while (c != '\n')
	{
		rd = read(fd, &c, 1);
		if (rd == -1)
		{
			free(s);
			return (NULL);
		}
		if (rd == 0)
			return (s);
		s = ft_charadd_end(s, c);
	}
	return (s);
}

int	ft_gnl_sh(char **line, int memory, int fd)
{
	char	*buffer;
	char	ch;
	int		i;
	int		rb;

	i = 0;
	rb = 0;
	buffer = (char *)malloc(memory * sizeof(char));
	if (!buffer)
		return (-1);
	rb = read(fd, &ch, 1);
	while (rb && ch && ch != '\n')
	{
		if (ch && ch != '\n')
			buffer[i] = ch;
		rb = read(fd, &ch, 1);
		i++;
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	return (rb);
}
