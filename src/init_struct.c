/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:16:50 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/24 19:32:26 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_dda_ray(t_win *win)
{
	win->ray.direction_x = 0;
	win->ray.direction_y = 0;
	win->ray.plane_x = 0.0;
	win->ray.plane_y = 0.0;
	win->ray.number = 0;
	win->ray.door = 0;
	win->ray.dda.direction_dda = 0;
	win->ray.dda.cell_distance_x = 0;
	win->ray.dda.cell_distance_y = 0;
	win->ray.dda.step_x = 0;
	win->ray.dda.step_y = 0;
	win->ray.dda.shift_x = 0;
	win->ray.dda.shift_y = 0;
}

static void	ft_init_wall_player(t_win *win)
{
	win->wall.row = 0.0;
	win->wall.column = 0.0;
	win->wall.height = 0;
	win->wall.start_pixel = 0;
	win->wall.distance = 0.0;
	win->player.map_position_x = 0;
	win->player.map_position_y = 0;
	win->player.position_x = 0.0;
	win->player.position_y = 0.0;
	win->player.direction_x = 0.0;
	win->player.direction_y = 0.0;
}

void	ft_init_img(t_win *win)
{
	win->ea.fd = -1;
	win->we.fd = -1;
	win->so.fd = -1;
	win->no.fd = -1;
	win->no.img = NULL;
	win->no.bits_per_pixel = 0;
	win->no.line_length = 0;
	win->no.endian = 0;
	win->we.img = NULL;
	win->we.bits_per_pixel = 0;
	win->we.line_length = 0;
	win->we.endian = 0;
	win->ea.img = NULL;
	win->ea.bits_per_pixel = 0;
	win->ea.line_length = 0;
	win->ea.endian = 0;
	win->so.img = NULL;
	win->so.bits_per_pixel = 0;
	win->so.line_length = 0;
	win->so.endian = 0;
	ft_init_wall_player(win);
	ft_init_dda_ray(win);
}

static void	mlx_hooks(t_win *win)
{
	win->sprite_counter = 0;
	win->flag_mouse = 0;
	win->past_mouse_pos_x = 0;
	win->flag_map = 0;
	win->sprite.switcher = 0;
	win->sprite.direction_dda = 0;
	win->sprite.shift_x = 0;
	win->sprite.shift_y = 0;
	win->sprite.count = 0;
	mlx_hook(win->win, 2, 1L << 0, &key_hook, win);
	mlx_hook(win->win, 17, 1L << 18, &destroy_hook, win);
	mlx_hook(win->win, 6, 1L << 6, &mouse_hook, win);
}

void	ft_init_mlx(t_win *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		error("MLX Error", 0);
	win->win = mlx_new_window(win->mlx, WIDTH_WIN, HEIGHT_WIN, "CUB3D");
	if (NULL == win->win)
		error("Window Error", 0);
	win->img = mlx_new_image(win->mlx, WIDTH_WIN, HEIGHT_WIN);
	win->player_mini.img = mlx_xpm_file_to_image(win->mlx, PLAYER,
			&win->player_mini.w, &win->player_mini.h);
	win->wall_mini.img = mlx_xpm_file_to_image(win->mlx, WALL,
			&win->wall_mini.w, &win->wall_mini.h);
	win->door_mini.img = mlx_xpm_file_to_image(win->mlx, DOOR,
			&win->door_mini.w, &win->door_mini.h);
	if (!win->img || !win->player_mini.img
		|| !win->door_mini.img || !win->wall_mini.img)
		error("IMG Error", 1);
	win->addr = mlx_get_data_addr(win->img,
			&win->bits_per_pixel, &win->line_length,
			&win->endian);
	if (!win->addr)
		error("IMG Fill(bpp etc) Error", 0);
	mlx_hooks(win);
}
