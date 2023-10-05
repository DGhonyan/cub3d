/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:36:00 by mtiesha           #+#    #+#             */
/*   Updated: 2022/05/20 17:40:32 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	int		len;
	char	*ptr;

	len = 0;
	while (str[len])
		len++;
	if (len > n)
		len = n;
	ptr = (char *)calloc(sizeof(char), len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
