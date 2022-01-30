/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:03:05 by cvine             #+#    #+#             */
/*   Updated: 2022/01/30 19:11:24 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	dst = data->addr + (x * 4 + data->line_length *  y);
// 	*(unsigned int *)dst = color;
// }

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int main(int argc, char **argv)
{
	t_vars	vars;
	t_map	*map = map_init();
	check_args (argc, argv);
	create_map (argv[1], map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 64 * map->width, 64 * map->height, "so_long");
	draw_map(&vars, map, 0, 0);
	mlx_hook(vars.win, 17, 1L<<0, close_window, &vars);
	mlx_loop(vars.mlx);
}
