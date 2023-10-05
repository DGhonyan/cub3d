/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:36:31 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/25 14:12:05 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_deldoublec(char **str, char c)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (1 + ft_strlen((*str))));
	if (ret == NULL)
		return (NULL);
	while ((*str)[i])
	{
		if ((*str)[i + 1] == '\0' \
			|| !((*str)[i] == c && (*str)[i] == (*str)[i + 1]))
			ret[j++] = (*str)[i];
		i++;
	}
	ret[j] = 0;
	free(*str);
	tmp = ft_strdup(ret);
	free(ret);
	return (tmp);
}
