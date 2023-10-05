/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/22 14:07:51 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_position(t_win *win, int x, int y, char dir)
{
	win->player.position_x = y + 0.5;
	win->player.position_y = x + 0.5;
	if (dir == 'N')
	{
		win->player.direction_x = 0.0;
		win->player.direction_y = -1.0;
		win->ray.plane_x = 0.70;
		win->ray.plane_y = 0.0;
	}
	else if (dir == 'S')
	{
		win->player.direction_x = 0.0;
		win->player.direction_y = 1.0;
		win->ray.plane_x = -0.70;
		win->ray.plane_y = 0.0;
	}
}

int	valid(char c, int check_surrounded)
{
	if (check_surrounded)
		return (c == '1' || c == '0');
	return (c == '\n' || c == '1' || c == '0' || c == 'N'
		|| c == 'W' || c == 'E' || c == 'S' || c == ' ' \
		|| c == '\t' || c == 'c');
}

void	parse_map(int argc, char **argv, t_win *win)
{
	int		fd;
	char	**map;
	char	**saved_map;

	if (argc == 1 || wrong_extension(argv[1], ".cub"))
		error ("Usage: ./cub3d maps/map[num].cub", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Can't open the map", 1);
	map = get_map(fd);
	saved_map = map;
	if (get_options(&map, win) || !map)
		error("Missing options", 0);
	map = convert_tabs(map, saved_map);
	validate_map(win, map);
	win->map = map;
	close(fd);
}
