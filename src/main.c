/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:04:03 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/24 17:28:48 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_win(t_win *win, int argc, char **argv)
{
	ft_init_img(win);
	ft_init_mlx(win);
	parse_map(argc, argv, win);
	ft_enter_doors(win);
	ft_add_sprites(win);
	store_xpm(&win->door, win->mlx, "xpm/door.xpm");
	store_xpm(&win->sprt1, win->mlx, "xpm/sprite1.xpm");
	store_xpm(&win->sprt2, win->mlx, "xpm/sprite2.xpm");
	store_xpm(&win->sprt3, win->mlx, "xpm/sprite3.xpm");
}

int	main(int argc, char **argv)
{
	t_win	win;

	init_win(&win, argc, argv);
	ft_render(&win);
	ft_putendl_fd("[Log] first render", 2);

	ft_putendl_fd("press M to open minimap, L to activate rotating with mouse, arrow keys to rotate, WASD to move, SPACE to open doors", 1);

	mlx_loop(win.mlx);
}
