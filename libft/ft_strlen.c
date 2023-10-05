/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:54:23 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/16 12:16:47 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string && string[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strnlen(const char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

size_t	ft_strrnlen(const char *str, char c)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	while (str_len >= 0 && str[str_len] != c)
	{
		str_len--;
		len++;
	}
	return (len);
}
