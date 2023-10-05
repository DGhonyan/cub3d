/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:47:29 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/24 19:36:06 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calc_shift_step(t_win *win)
{
	if (win->ray.direction_x < 0)
	{
		win->ray.dda.step_x = -1;
		win->ray.dda.shift_x = (win->player.position_x - \
			win->player.map_position_x) * win->ray.dda.cell_distance_x;
	}
	else if (win->ray.direction_x >= 0)
	{
		win->ray.dda.step_x = 1;
		win->ray.dda.shift_x = (win->player.map_position_x + 1.0 \
			- win->player.position_x) * win->ray.dda.cell_distance_x;
	}
	if (win->ray.direction_y < 0)
	{
		win->ray.dda.step_y = -1;
		win->ray.dda.shift_y = (win->player.position_y - \
			win->player.map_position_y) * win->ray.dda.cell_distance_y;
	}
	else if (win->ray.direction_y >= 0)
	{
		win->ray.dda.step_y = 1;
		win->ray.dda.shift_y = (win->player.map_position_y + \
			1.0 - win->player.position_y) * win->ray.dda.cell_distance_y;
	}
}

static void	ft_calc_ray_data(t_win *win)
{
	double	field_point;

	win->player.map_position_x = (int)win->player.position_x;
	win->player.map_position_y = (int)win->player.position_y;
	field_point = 2.0 * win->ray.number / WIDTH_WIN - 1.0;
	win->ray.direction_x = win->player.direction_x + \
		win->ray.plane_x * field_point;
	win->ray.direction_y = win->player.direction_y + \
		win->ray.plane_y * field_point;
	win->ray.dda.cell_distance_x = fabs(1 / win->ray.direction_x);
	win->ray.dda.cell_distance_y = fabs(1 / win->ray.direction_y);
	ft_calc_shift_step(win);
}

void	dda_norm(t_win *win)
{
	if (win->ray.dda.shift_x < win->ray.dda.shift_y)
	{
		win->ray.dda.shift_x += win->ray.dda.cell_distance_x;
		win->player.map_position_x += win->ray.dda.step_x;
		win->ray.dda.direction_dda = 0;
	}
	else
	{
		win->ray.dda.shift_y += win->ray.dda.cell_distance_y;
		win->player.map_position_y += win->ray.dda.step_y;
		win->ray.dda.direction_dda = 1;
	}
}

static void	ft_calc_dda_dir(t_win *win)
{
	char	cell;

	while (1)
	{
		dda_norm(win);
		cell = win->map[win->player.map_position_y][win->player.map_position_x];
		if (cell == SPRITE && win->sprite.count == 0)
		{
			win->sprite.count++;
			win->sprite.direction_dda = win->ray.dda.direction_dda;
			win->sprite.shift_x = win->ray.dda.shift_x;
			win->sprite.shift_y = win->ray.dda.shift_y;
			win->sprite.is_sprite = 1;
		}
		if (cell == '1' || cell == CLOSE_DOOR)
		{
			if (cell == CLOSE_DOOR)
				win->ray.door = 1;
			break ;
		}
	}
}

int	*ft_render(t_win *win)
{
	win->ray.number = 0;
	drow_floor_and_ceil(win);
	while (win->ray.number < WIDTH_WIN)
	{
		ft_calc_ray_data(win);
		ft_calc_dda_dir(win);
		ft_calc_dist_height_wall(win);
		ft_calc_row_wall(win);
		ft_draw_wall(win);
		if (win->sprite.is_sprite)
		{
			ft_calc_dist_height_wall_s(win);
			ft_calc_row_wall_s(win);
			ft_draw_wall_s(win);
			win->sprite.is_sprite = 0;
			win->sprite.count = 0;
		}
		++win->ray.number;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	if (win->flag_map)
		draw_minimap(win);
	return (0);
}
