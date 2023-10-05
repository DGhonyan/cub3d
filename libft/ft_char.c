/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:19:25 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/25 14:15:15 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chardel(char **str, int index)
{
	char	*ret;

	ret = NULL;
	ret = (char *)ft_calloc(ft_strlen((*str)), sizeof(char));
	ret = (char *)ft_memcpy(ret, (*str), index);
	while ((*str)[++index])
		ret[index - 1] = (*str)[index];
	free(*str);
	return (ret);
}

char	*ft_charadd_end(char *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(sizeof (*res) * (ft_strlen(s) + 2));
	if (!res)
	{
		free(s);
		return (NULL);
	}
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}

char	*ft_charadd(char **str, int index, char c)
{
	char	*ret;

	ret = NULL;
	ret = (char *)ft_calloc(2 + ft_strlen((*str)), sizeof(char));
	ret = (char *)ft_memcpy(ret, (*str), index);
	ret[index] = c;
	while ((*str)[index])
	{
		ret[index + 1] = (*str)[index];
		index++;
	}
	free(*str);
	return (ret);
}

size_t	ft_count_char(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (c == str[i])
			count++;
		i++;
	}
	return (count);
}
