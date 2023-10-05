/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:41:24 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/24 19:38:44 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_dist_height_wall_s(t_win *win)
{
	if (win->sprite.direction_dda)
		win->wall.distance = win->sprite.shift_y \
			- win->ray.dda.cell_distance_y;
	else
		win->wall.distance = win->sprite.shift_x \
			- win->ray.dda.cell_distance_x;
	win->wall.height = (int)(HEIGHT_WIN / win->wall.distance);
	win->wall.start_pixel = HEIGHT_WIN / 2 - win->wall.height / 2;
	if (win->wall.start_pixel < 0)
		win->wall.start_pixel = 0;
}

void	ft_calc_row_wall_s(t_win *win)
{
	double	column;

	if (win->sprite.direction_dda)
		column = win->player.position_x + win->wall.distance * \
		win->ray.direction_x;
	else
		column = win->player.position_y + win->wall.distance * \
		win->ray.direction_y;
	column -= floor(column);
	win->wall.column = (int)(column * 64);
}

static int	ft_get_color_s(t_win *win)
{
	int	*wall;

	if (win->sprite.switcher >= 13)
		win->sprite.switcher = 0;
	if (win->sprite.switcher >= 0 && win->sprite.switcher <= 4)
	{
		wall = (int *)win->sprt1.addr;
	}
	else if (win->sprite.switcher > 4 && win->sprite.switcher <= 9)
	{
		wall = (int *)win->sprt2.addr;
	}
	else if (win->sprite.switcher >= 10 && win->sprite.switcher <= 12)
	{
		wall = (int *)win->sprt3.addr;
	}
	return (wall[64 * (int)win->wall.row + (int)win->wall.column]);
}	

void	ft_draw_wall_s(t_win *win)
{
	double	interpolation;
	int		color;
	int		i;

	i = 0;
	win->wall.row = 0;
	if (win->wall.distance < 1)
		win->wall.row = (64.0 - 64.0 * win->wall.distance) / 2;
	interpolation = (double)64 / (double)win->wall.height;
	while (i < win->wall.height && i < HEIGHT_WIN)
	{
		color = ft_get_color_s(win);
		if (color != 0xFFFFFF)
			ft_put_pixel(win, win->ray.number, \
				win->wall.start_pixel + i, color);
		win->wall.row += interpolation;
		++i;
	}
	win->ray.door = 0;
}
