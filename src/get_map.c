/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <dghonyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/09/25 17:34:21 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wrong_extension(char *s, char *extension)
{
	int	i;

	if (ft_strlen(s) < 4)
		return (1);
	i = ft_strlen(s) - 4;
	return (ft_strncmp(&s[i], extension, ft_strlen(extension)));
}

char	**list_to_arr(t_list *map)
{
	int		i;
	char	**res;
	t_list	*temp;

	i = 0;
	temp = map;
	res = malloc(sizeof (*res) * (ft_lstsize(map) + 1));
	if (!res)
		error("malloc", 1);
	while (map)
	{
		res[i] = ft_strdup(map->content);
		if (!res[i])
		{
			ft_splfree(res);
			error("malloc", 1);
		}
		i++;
		map = map->next;
	}
	res[i] = NULL;
	ft_lstclear(&temp, free);
	return (res);
}

char	**get_map(int fd)
{
	char	*line;
	t_list	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	return (list_to_arr(map));
}
