/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:17:59 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/21 15:05:44 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define SPEED 0.1
#define SPEED_D 0.3
#define ROT_SPEED 0.05

void	move_up_down(t_win *win, int keycode)
{
	char	tmp;

	if (keycode == UP)
	{
		tmp = win->map[(int)(win->player.position_y + win->player.direction_y \
			* (SPEED_D))][(int)win->player.position_x];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_y += win->player.direction_y * SPEED;
		tmp = win->map[(int)win->player.position_y] \
		[(int)(win->player.position_x + win->player.direction_x * SPEED_D)];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_x += win->player.direction_x * SPEED;
	}
	else if (keycode == DOWN)
	{
		tmp = win->map[(int)(win->player.position_y - win->player.direction_y \
			* SPEED_D)][(int)win->player.position_x];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_y -= win->player.direction_y * SPEED;
		tmp = win->map[(int)win->player.position_y] \
		[(int)(win->player.position_x - win->player.direction_x * SPEED_D)];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_x -= win->player.direction_x * SPEED;
	}
}

void	move_left_right(t_win *win, int keycode)
{
	int		tmp;

	if (keycode == RIGHT)
	{
		tmp = win->map[(int)(win->player.position_y + win->ray.plane_y \
			* SPEED_D)][(int)win->player.position_x];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_y += win->ray.plane_y * SPEED;
		tmp = win->map[(int)win->player.position_y] \
		[(int)(win->player.position_x + win->ray.plane_x * SPEED_D)];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_x += win->ray.plane_x * SPEED;
	}
	else if (keycode == LEFT)
	{
		tmp = win->map[(int)(win->player.position_y - win->ray.plane_y \
			* SPEED_D)][(int)win->player.position_x];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_y -= win->ray.plane_y * SPEED;
		tmp = win->map[(int)win->player.position_y] \
		[(int)(win->player.position_x - win->ray.plane_x * SPEED_D)];
		if (tmp != '1' && tmp != CLOSE_DOOR)
			win->player.position_x -= win->ray.plane_x * SPEED;
	}
}

void	rotate_left(t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = win->player.direction_x;
	win->player.direction_x = win->player.direction_x * cos(-ROT_SPEED) - \
	win->player.direction_y * sin(-ROT_SPEED);
	win->player.direction_y = old_dir_x * sin(-ROT_SPEED) + \
	win->player.direction_y * cos(-ROT_SPEED);
	old_plane_x = win->ray.plane_x;
	win->ray.plane_x = win->ray.plane_x * cos(-ROT_SPEED) - \
	win->ray.plane_y * sin(-ROT_SPEED);
	win->ray.plane_y = old_plane_x * sin(-ROT_SPEED) + \
	win->ray.plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = win->player.direction_x;
	win->player.direction_x = win->player.direction_x * cos(ROT_SPEED) - \
	win->player.direction_y * sin(ROT_SPEED);
	win->player.direction_y = old_dir_x * sin(ROT_SPEED) + \
	win->player.direction_y * cos(ROT_SPEED);
	old_plane_x = win->ray.plane_x;
	win->ray.plane_x = win->ray.plane_x * cos(ROT_SPEED) - \
	win->ray.plane_y * sin(ROT_SPEED);
	win->ray.plane_y = old_plane_x * sin(ROT_SPEED) + \
	win->ray.plane_y * cos(ROT_SPEED);
}
