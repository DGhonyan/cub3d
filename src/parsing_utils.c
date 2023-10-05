/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/22 08:44:48 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_player(t_win *win, char dir, int x, int y)
{
	set_position(win, x, y, dir);
	if (dir == 'W')
	{
		win->player.direction_x = -1.0;
		win->player.direction_y = 0.0;
		win->ray.plane_x = 0.0;
		win->ray.plane_y = -0.70;
	}
	else if (dir == 'E')
	{
		win->player.direction_x = 1.0;
		win->player.direction_y = 0.0;
		win->ray.plane_x = 0.0;
		win->ray.plane_y = 0.70;
	}
}

int	space_or_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen_map(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			len += 4;
		else
			len++;
		i++;
	}
	return (len);
}

char	*convert(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = ((j = 0) && 0);
	res = malloc(sizeof (*res) * (ft_strlen_map(s) + 1));
	if (!res)
		error("malloc", 1);
	while (s[i])
	{
		k = -1;
		if (s[i] == '\t')
		{
			while (++k < 4)
				res[j++] = ' ';
			i++;
		}
		else
			res[j++] = s[i++];
	}
	res[j] = '\0';
	return (res);
}

char	**convert_tabs(char **map, char **saved)
{
	int		i;
	char	**res;

	i = -1;
	res = malloc(sizeof (*res) * (ft_spllen(map) + 1));
	if (!res)
		error("malloc", 1);
	while (map[++i])
		res[i] = convert(map[i]);
	res[i] = NULL;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(saved);
	return (res);
}
