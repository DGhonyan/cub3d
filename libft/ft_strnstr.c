/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:54:23 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/19 13:56:27 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)(haystack));
	while (*haystack && n >= needle_len)
	{
		if (*haystack == *needle
			&& ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)(haystack));
		haystack++;
		n--;
	}
	return (NULL);
}

char	*ft_strrnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;
	size_t	stack_len;

	needle_len = ft_strlen(needle) - 1;
	stack_len = ft_strlen(haystack) - 1;
	if (needle_len == 0)
		return ((char *)(haystack));
	while (haystack[stack_len] && n >= needle_len)
	{
		if (haystack[stack_len] == needle[needle_len]
			&& 0 == ft_strncmp(haystack + (stack_len - needle_len), \
				needle, needle_len))
			return ((char *)(haystack + (stack_len - needle_len)));
		stack_len--;
		n--;
	}
	return (NULL);
}
