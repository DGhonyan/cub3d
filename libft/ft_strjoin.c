/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:54:23 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/18 13:26:05 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t			str1_len;
	size_t			str2_len;
	size_t			str1str2_len;
	unsigned char	*ret;

	if (!str1 && !str2)
		return (ft_strdup(""));
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	str1str2_len = str1_len + str2_len;
	ret = malloc((str1str2_len + 1) * sizeof(char));
	if (ret != NULL)
	{
		ft_memcpy(ret, str1, str1_len);
		ft_memcpy(ret + str1_len, str2, str2_len);
		ret[str1str2_len] = 0;
		return ((char *)(ret));
	}
	return (NULL);
}

char	*ft_strjoinchar(char const *str1, char const *str2, char c)
{
	char	*ret;
	char	*ptr;

	if (!str1 && !str2)
		return (ft_strdup(""));
	if (!str1)
		return (ft_strdup(str2));
	ptr = (char *)malloc(sizeof(char) * 2);
	ptr[0] = c;
	ptr[1] = 0;
	if (!str2)
	{
		ret = ft_strjoin(str1, ptr);
		free(ptr);
		return ((char *)(ret));
	}
	ret = ft_strjoin(str1, ptr);
	free(ptr);
	ptr = ft_strjoin(ret, str2);
	free(ret);
	return (ptr);
}

char	*ft_strjoinfree(char **str1, char **str2, int free_flag)
{
	char	*ret;

	ret = ft_strjoin((*str1), (*str2));
	if (!ret)
		return (NULL);
	if (0 == free_flag)
		free(*str1);
	else if (1 == free_flag)
		free(*str2);
	else if (2 == free_flag)
	{
		free(*str1);
		free(*str2);
	}
	return (ret);
}

char	*ft_strjoinfree_v2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	res = malloc(sizeof (*res) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[++i])
		res[i] = s1[i];
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	res[i] = '\0';
	return (res);
}
