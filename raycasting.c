/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:59:33 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/14 15:16:03 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_step_and_sideDist(t_game *game, t_map *map)
{
	if (map->rayDir_x < 0)
	{ 
		map->step_x = -1;
		map->sideDist_x = (game->pos.pos_x - map->map_x) * map->DeltaDist_x ;
	}
	else
	{
		map->step_x = 1;
		map->sideDist_x = (map->map_x + 1.0 - game->pos.pos_x) \
		* map->DeltaDist_x;
	}
	if (map->rayDir_y < 0)
	{
		map->step_y = -1;
		map->sideDist_y = (game->pos.pos_y - map->map_y) * map->DeltaDist_y;
	}
	else
	{
		map->step_y = 1 ;
		map->sideDist_y = (map->map_y + 1.0 - game->pos.pos_y) \
		* map->DeltaDist_y;
	}
}

static void	init_map_vars(t_map *map, t_game *game)
{
	map->map_x = (int)game->pos.pos_x;
	map->map_y = (int)game->pos.pos_y;
	map->hit = 0;
	if (map->rayDir_x == 0)
		map->DeltaDist_x = 1e30;
	else
		map->DeltaDist_x = fabs(1 / map->rayDir_x);
	if (map->rayDir_y == 0)
		map->DeltaDist_y = 1e30;
	else
		map->DeltaDist_y = fabs(1 / map->rayDir_y);
}

static void	init_vectors(t_game *game)
{
	game->pos.pos_x = 22;
	game->pos.pos_y = 12;
	game->pos.dir_x = -1;
	game->pos.dir_y = 0;
	game->pos.plane_x = 0;
	game->pos.plane_y = -0.66;
	game->time = 0;
	game->old_time = 0;
}

void	raycasting(t_game *game, t_cube *cube)
{
	t_map	map;
	int		x;
	int		*img_data_ptr;
	int		bits_per_pixel;
    int		size_line;
    int		endian;


	x = -1;
	init_vectors(&game);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img_data = (int *)mlx_get_data_addr(game->img, &bits_per_pixel, &size_line, &endian);
	while (++x < WIDTH)
	{
		map.camera_x = 2 * x / (double)WIDTH - 1;
		map.rayDir_x = game->pos.dir_x + game->pos.plane_x * map.camera_x;
		map.rayDir_y = game->pos.dir_y + game->pos.plane_y * map.camera_x;
		init_map_vars(&map, &game);
		get_step_and_sideDist(game, &map);
		draw_lines_dda(game, &map, cube);
		get_dist_to_wall(game, &map, cube);
		get_wall_height(game, &map, cube);
		set_wall_color(&map, cube, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
}
