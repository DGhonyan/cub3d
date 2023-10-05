/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:01:40 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/24 19:18:44 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == ESC)
		destroy_hook(win);
	else if (keycode == UP || keycode == DOWN)
	{
		++win->sprite.switcher;
		move_up_down(win, keycode);
	}
	else if (keycode == LEFT || keycode == RIGHT)
	{
		++win->sprite.switcher;
		move_left_right(win, keycode);
	}
	else if (keycode == ROTATE_LEFT)
		rotate_left(win);
	else if (keycode == ROTATE_RIGHT)
		rotate_right(win);
	else if (keycode == M_KEY)
		win->flag_map = 1 - win->flag_map - 0;
	else if (keycode == N_KEY)
		win->flag_mouse = 1 - win->flag_mouse - 0;
	else if (keycode == SPACE_KEY)
		ft_open_close_door(win);
	ft_render(win);
	return (0);
}

int	mouse_hook(int x, int y, t_win *win)
{
	if (win->flag_mouse && ((x > 0 && y > 0) \
		&& (x <= WIDTH_WIN && y <= HEIGHT_WIN)))
	{
		if (win->past_mouse_pos_x > x)
			key_hook(ROTATE_LEFT, win);
		if (win->past_mouse_pos_x < x)
			key_hook(ROTATE_RIGHT, win);
		win->past_mouse_pos_x = x;
	}
	return (0);
}

int	destroy_hook(t_win *win)
{
	(void)win;
	exit(EXIT_SUCCESS);
}
