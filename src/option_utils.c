/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/21 16:11:18 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_check(char *s, char *check[6])
{
	int	j;

	j = 0;
	while (check[j])
	{
		if (!ft_strcmp(s, check[j]))
			return (1);
		j++;
	}
	return (0);
}

void	store_xpm(t_img *img, void *mlx, char *name)
{
	img->fd = open(name, O_RDONLY);
	if (img->fd < 0)
		file_error(name);
	img->img = mlx_xpm_file_to_image(mlx, name, &(img->w), &(img->h));
	if (!img->img || img->w != 64 || img->h != 64)
	{
		close(img->fd);
		error("File size not supported, only 64x64", 0);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
	{
		close(img->fd);
		error(name, 0);
	}
}

void	check_colors(char *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == ',')
			count++;
	}
	if (count != 2)
		error ("Wrong colors", 0);
}

void	store_colors(int *color, char *s)
{
	int		i;
	int		j;
	char	**colors;

	i = -1;
	check_colors(s);
	colors = ft_split(s, ',');
	if (ft_spllen(colors) != 3)
		error ("Wrong colors", 0);
	while (colors[++i])
	{
		j = -1;
		while (colors[i][++j])
			if (colors[i][j] < '0' || colors[i][j] > '9')
				error("Wrong colors", 0);
	}
	i = -1;
	if (ft_atoi(colors[0]) < 0 || ft_atoi(colors[0]) > 255
		|| ft_atoi(colors[1]) < 0 || ft_atoi(colors[1]) > 255
		|| ft_atoi(colors[2]) < 0 || ft_atoi(colors[2]) > 255)
		error("Wrong colors", 0);
	*color = ft_atoi(colors[0]) << 16
		| ft_atoi(colors[1]) << 8 | ft_atoi(colors[2]);
	ft_splfree(colors);
}

void	store_textures(char **line, t_win *win)
{
	if (!ft_strcmp(line[0], "NO"))
		store_xpm(&(win->no), win->mlx, line[1]);
	if (!ft_strcmp(line[0], "EA"))
		store_xpm(&(win->ea), win->mlx, line[1]);
	if (!ft_strcmp(line[0], "WE"))
		store_xpm(&(win->we), win->mlx, line[1]);
	if (!ft_strcmp(line[0], "SO"))
		store_xpm(&(win->so), win->mlx, line[1]);
	if (!ft_strcmp(line[0], "F"))
		store_colors(&(win->f_color), line[1]);
	if (!ft_strcmp(line[0], "C"))
		store_colors(&(win->c_color), line[1]);
}
