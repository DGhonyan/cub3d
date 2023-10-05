/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/14 18:20:08 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_in_check(char *s, char *check[6]);
void	init_check(char *(*check)[7]);
void	store_textures(char **line, t_win *win);

void	init_check(char *(*check)[7])
{
	int	i;

	i = 0;
	while (i < 7)
		(*check)[i++] = NULL;
}

int	is_allowed(char *s)
{
	return (!ft_strcmp(s, "NO") || !ft_strcmp(s, "WE")
		|| !ft_strcmp(s, "EA") || !ft_strcmp(s, "SO")
		|| !ft_strcmp(s, "F") || !ft_strcmp(s, "C"));
}

void	process_line(char **line)
{
	if (!line)
		error("malloc", 1);
	if (!is_allowed(line[0]) || ft_spllen(line) != 2)
		error("Wrong options", 0);
}

char	**pass_nl(char **map, int first)
{
	char	*temp;

	if (!first)
	{
		temp = *map;
		map++;
		free(temp);
	}
	while (*map && space_or_nl(*map))
	{
		temp = *map;
		map++;
		free(temp);
	}
	return (map);
}

int	get_options(char ***map, t_win *win)
{
	int		i;
	int		j;
	char	**line;
	char	*check[7];

	i = 0;
	*map = pass_nl(*map, 1);
	init_check(&check);
	while (**map && i != 6)
	{
		line = ft_split_str(**map, " \t\n");
		process_line(line);
		if (i && is_in_check(line[0], check))
			error("Duplicates", 0);
		check[i++] = ft_strdup(line[0]);
		store_textures(line, win);
		ft_splfree(line);
		*map = pass_nl(*map, 0);
	}
	j = -1;
	while (check[++j])
		free(check[j]);
	return (i != 6);
}
