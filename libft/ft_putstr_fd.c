/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:54:23 by mtiesha           #+#    #+#             */
/*   Updated: 2022/05/23 06:47:30 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL && fd != -1)
		i += write(fd, s, ft_strlen(s));
	return (i);
}

int	ft_putnstr_fd(char *str, int n, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str || !fd)
		return (0);
	while (str[i] && i <= n)
	{
		len += write(fd, &str[i], 1);
		i++;
	}
	return (len);
}
