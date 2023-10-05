/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/20 19:47:57 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_int(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int	max_len(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = ft_strlen_int(map[0]);
	while (map[++i])
	{
		if (max < ft_strlen_int(map[i]))
			max = ft_strlen_int(map[i]);
	}
	return (max);
}

void	draw_minimap(t_win *win)
{
	int	i;
	int	j;
	int	map_len;

	i = 0;
	map_len = have_newlines(win->map);
	while (i < map_len && i <= HEIGHT_WIN / win->wall_mini.h)
	{
		j = 0;
		while (j < ft_strlen_int(win->map[i])
			&& j <= WIDTH_WIN / win->wall_mini.w)
		{
			if (win->map[i][j] == '1')
				mlx_put_image_to_window(win->mlx, win->win, win->wall_mini.img,
					j * win->wall_mini.w, i * win->wall_mini.h);
			else if (win->map[i][j] == 'd')
				mlx_put_image_to_window(win->mlx, win->win, win->door_mini.img,
					j * win->door_mini.w, i * win->door_mini.h);
			j++;
		}
		i++;
	}
}
