/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:54:23 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/06 17:12:25 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(char const *s, char *c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(c, s[i]))
			i++;
		if (s[i] && !ft_strchr(c, s[i]))
		{
			while (s[i] && !ft_strchr(c, s[i]))
				i++;
			count++;
		}
	}
	return (count);
}

static size_t	ft_len_not_c(char const *s, char *c)
{
	size_t	len;

	len = 0;
	while (*s && !ft_strchr(c, *s))
	{
		s++;
		len++;
	}
	return (len);
}

static char	**ft_array_write(const char *s, char *c, char **ret)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && ft_strchr(c, *s))
			s++;
		if (*s && !ft_strchr(c, *s))
		{
			ret[i] = ft_substr(s, 0, ft_len_not_c(s, c));
			s += ft_len_not_c(s, c);
			if (!ret[i])
			{
				ft_splfree(ret);
				return (NULL);
			}
			i++;
		}
	}
	ret[i] = NULL;
	return (ret);
}

/*  split s by all characters in c  */
char	**ft_split_str(char const *s, char *c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = malloc(sizeof (*ret) * (ft_counter(s, c) + 1));
	if (!ret)
		return (NULL);
	return (ft_array_write(s, c, ret));
}
