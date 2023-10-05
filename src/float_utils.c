/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:59:24 by mtiesha           #+#    #+#             */
/*   Updated: 2022/09/11 14:02:01 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_vld_f(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '.' && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

double	ft_atoi_f(const char *str)
{
	double	num_ud;
	double	num_ad;
	char	*tmp;
	int		len;

	tmp = (char *)str;
	num_ud = (double)ft_atoi(tmp);
	while (tmp && *tmp != '.' && *tmp)
		tmp++;
	tmp++;
	num_ad = (double)ft_atoi(tmp);
	len = ft_strlen(tmp);
	while (len--)
		num_ad /= 10;
	if (num_ud >= 0 && str[0] != '-')
		return (num_ud + num_ad);
	else
		return (num_ud - num_ad);
}
