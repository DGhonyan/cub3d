/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_seil_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:29:21 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/16 16:43:10 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_floor_and_ceil(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT_WIN / 2)
	{
		j = 0;
		while (j < WIDTH_WIN)
		{
			ft_put_pixel(win, j, i, win->c_color);
			++j;
		}
		++i;
	}
	while (i < HEIGHT_WIN)
	{
		j = 0;
		while (j < WIDTH_WIN)
		{
			ft_put_pixel(win, j, i, win->f_color);
			++j;
		}
		++i;
	}
}

void	ft_calc_dist_height_wall(t_win *win)
{
	if (win->ray.dda.direction_dda)
		win->wall.distance = win->ray.dda.shift_y \
			- win->ray.dda.cell_distance_y;
	else
		win->wall.distance = win->ray.dda.shift_x \
			- win->ray.dda.cell_distance_x;
	win->wall.height = (int)(HEIGHT_WIN / win->wall.distance);
	win->wall.start_pixel = HEIGHT_WIN / 2 - win->wall.height / 2;
}

void	ft_calc_row_wall(t_win *win)
{
	double	column;

	if (win->ray.dda.direction_dda)
		column = win->player.position_x + win->wall.distance * \
        win->ray.direction_x;
	else
		column = win->player.position_y + win->wall.distance * \
        win->ray.direction_y;
	column -= floor(column);
	win->wall.column = (int)(column * 64);
	// if ((0 == win->ray.dda.direction_dda && win->ray.direction_x > 0)
	// 	|| (win->ray.dda.direction_dda && win->ray.direction_y < 0))
	// 	win->wall.column = 64 - win->wall.column - 1;
}

static int	ft_find_pixel(t_win *win, int x, int y)
{
	int	*wall;

	if (win->ray.dda.direction_dda)
	{
		if (win->ray.direction_y >= 0)
			wall = (int *)win->so.addr;
		else
			wall = (int *)win->no.addr;
	}
	else
	{
		if (win->ray.direction_x >= 0)
			wall = (int *)win->ea.addr;
		else
			wall = (int *)win->we.addr;
	}
	return (wall[64 * x + y]);
}

void	ft_draw_wall(t_win *win)
{
	double	interpolation;
	int		color;
	int		i;

	i = 0;
	win->wall.row = 0;
	interpolation = (double)64 / (double)win->wall.height;
	while (i < win->wall.height)
	{
		color = ft_find_pixel(win, win->wall.row, \
			(int)win->wall.column);
		ft_put_pixel(win, win->ray.number, win->wall.start_pixel + i, color);
		win->wall.row += interpolation;
		++i;
	}
}
