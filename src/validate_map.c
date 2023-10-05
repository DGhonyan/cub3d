/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/22 08:48:28 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* so many things to change */

#include "cub3d.h"

int	check_characters(t_win *win, char **map, int len)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'N' || map[i][j] == 'S')
			{
				player++;
				ft_set_player(win, map[i][j], i, j);
				map[i][j] = '0';
			}
			if (!valid(map[i][j], 0))
				return (0);
		}
	}
	return (player == 1);
}

int	have_newlines(char **map)
{
	int	i;
	int	nl_index;

	i = 0;
	nl_index = 0;
	while (map[i] && !space_or_nl(map[i]))
		i++;
	nl_index = i;
	while (map[nl_index] && space_or_nl(map[nl_index]))
		nl_index++;
	if (!map[nl_index])
		return (i);
	return (-1);
}

int	first_last(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			if (s[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

int	middle(char *s, char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			if (s[i] == '0' && ((ft_strlen_map(s1) < i || ft_strlen_map(s2) < i
						|| !valid(s[i - 1], 1) || !valid(s[i + 1], 1)
						|| !valid(s1[i], 1) || !valid(s2[i], 1)
						|| !valid(s1[i - 1], 1) || !valid(s2[i - 1], 1)
						|| !valid(s1[i + 1], 1) || !valid(s2[i + 1], 1))))
				return (0);
			i++;
		}
	}
	return (1);
}

int	validate_map(t_win *win, char **map)
{
	int	i;
	int	len;

	i = -1;
	len = have_newlines(map);
	if (len < 0)
		error("Wrong map", 0);
	if (!check_characters(win, map, len))
		error("Something's wrong with characters...", 0);
	while (++i < len)
	{
		if ((i == 0 || i == len - 1) && !first_last(map[i]))
			error("Map not surrunded by walls 1", 0);
		else if (i > 0 && i < len - 1
			&& !middle(map[i], map[i - 1], map[i + 1]))
			error("Map not surrunded by walls 2", 0);
	}
	return (0);
}
