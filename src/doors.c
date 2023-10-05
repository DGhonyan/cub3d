/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:53:27 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/22 15:21:47 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enter_doors(t_win *win)
{
	int	i;
	int	j;

	i = 1;
	while (i < ft_spllen(win->map))
	{
		j = 0;
		while (win->map[i][j])
		{
			if ('0' == win->map[i][j] && j >= 1 && j < \
			(int)ft_strlen(win->map[i]) && '1' == win->map[i][j + 1] \
			&& '1' == win->map[i][j - 1] && '0' == win->map[i - 1][j] \
			&& '0' == win->map[i + 1][j])
				win->map[i][j] = CLOSE_DOOR;
			++j;
		}
		++i;
	}
}

void	ft_add_sprites(t_win *win)
{
	int	i;
	int	j;

	i = 1;
	while (i < ft_spllen(win->map))
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == '0'
					&& i < have_newlines(win->map) - 1 && i > 0
					&& j < (int)ft_strlen(win->map[i + 1])
					&& j < (int)ft_strlen(win->map[i - 1])
					&& win->map[i + 1][j] == '0'
					&& win->map[i - 1][j] == '0'
					&& win->map[i][j + 1] == '0'
					&& win->map[i][j - 1] == '0')
				win->map[i][j] = SPRITE;
			++j;
		}
		++i;
	}
}

void	ft_open_close_door(t_win *win)
{
	int	x;
	int	y;
	int	m;

	m = 0;
	x = (int)win->player.position_x;
	y = (int)win->player.position_y;
	if ((win->map[y - 1][x] == CLOSE_DOOR \
		|| win->map[y - 1][x] == OPEN_DOOR) && win->player.direction_y < 0)
		m = -1;
	else if ((win->map[y + 1][x] == CLOSE_DOOR \
		|| win->map[y + 1][x] == OPEN_DOOR) && win->player.direction_y >= 0)
		m = 1;
	if (win->map[y + m][x] == OPEN_DOOR || win->map[y + m][x] == OPEN_DOOR \
		|| win->map[y + m][x] == CLOSE_DOOR || win->map[y + m][x] == CLOSE_DOOR)
	{
		if (win->map[y + m][x] == CLOSE_DOOR)
			win->map[y + m][x] = OPEN_DOOR;
		else
			win->map[y + m][x] = CLOSE_DOOR;
	}
}
