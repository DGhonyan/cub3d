/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:18:21 by mtiesha           #+#    #+#             */
/*   Updated: 2022/09/11 14:00:07 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_put_pixel(t_win *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)(dst) = color;
}
