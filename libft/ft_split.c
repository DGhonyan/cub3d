/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:54:23 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/22 08:33:28 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != 0 && *s != c)
			count++;
		while (*s != c && *s != 0)
			s++;
	}
	if (count == 0)
		count = 1;
	return (count);
}

static size_t	ft_len_not_c(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s != 0)
	{
		count++;
		s++;
	}
	return (count);
}

static char	**ft_array_write(const char *str, char c, char **ret)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != 0 && *str != c)
		{
			ret[i] = ft_substr(str, 0, ft_len_not_c(str, c));
			if (ret[i] == NULL)
				return (NULL);
			i++;
		}
		while (*str != c && *str != 0)
			str++;
	}
	ret[i] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_counter(s, c);
	ret = (char **)ft_calloc(count + 1, sizeof(char *));
	if (ret == NULL)
		return (NULL);
	if (*s)
		ret = ft_array_write(s, c, ret);
	return (ret);
}

size_t	ft_putspl_fd(char **split, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (split[i])
	{
		len += write(fd, ft_itoa(i), 2);
		len += write(fd, ": ", 1);
		len += write(fd, split[i], ft_strlen(split[i]));
		len += write(fd, "\n", 1);
		i++;
	}
	return (len);
}
