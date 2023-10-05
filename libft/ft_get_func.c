/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:56:14 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/16 12:36:03 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*	ft_get_strnspl - find str in arrays an array, to full search put \0 to last arg
*/

char	*ft_get_strnspl(char **spl, char *str, char c)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		if (!ft_memcmp(spl[i], str, ft_strnlen(spl[i], c)))
			return (spl[i]);
		i++;
	}
	return (NULL);
}

int	ft_get_minmax(int a, int b, char *min_or_max)
{
	if ('i' == min_or_max[1])
	{
		if (a > b)
			return (b);
		return (a);
	}
	if (a < b)
		return (b);
	else if (a > b)
		return (a);
	if (a == b)
		return (0);
	return (-1);
}
