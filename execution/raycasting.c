/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:59:33 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/18 10:00:52 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_step_and_side_dist(t_map *map)
{
	if (map->ray_dir.x < 0)
	{
		map->step_x = -1;
		map->side_dist.x = (map->pos.x - map->map_x) * map->delta_dist.x ;
	}
	else
	{
		map->step_x = 1;
		map->side_dist.x = (map->map_x + 1.0 - map->pos.x) \
		* map->delta_dist.x;
	}
	if (map->ray_dir.y < 0)
	{
		map->step_y = -1;
		map->side_dist.y = (map->pos.y - map->map_y) * map->delta_dist.y;
	}
	else
	{
		map->step_y = 1 ;
		map->side_dist.y = (map->map_y + 1.0 - map->pos.y) \
		* map->delta_dist.y;
	}
}

static void	init_map_vars(t_map *map)
{
	map->map_x = (int)map->pos.x;
	map->map_y = (int)map->pos.y;
	map->hit = 0;
	if (map->ray_dir.x == 0)
		map->delta_dist.x = 1e30;
	else
		map->delta_dist.x = fabs(1 / map->ray_dir.x);
	if (map->ray_dir.y == 0)
		map->delta_dist.y = 1e30;
	else
		map->delta_dist.y = fabs(1 / map->ray_dir.y);
}

static void	init_vectors(t_map *map)
{
	map->dir.x = -1;
	map->dir.y = 0;
	map->plane.x = 0;
	map->plane.y = -0.66;
}

void	raycasting(t_game *game, t_map *map, t_cube *cube)
{
	int	x;

	x = -1;
	init_vectors(map);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img_data = mlx_get_data_addr(game->img, \
	&game->bits_per_pixel, &game->size_line, &game->endian);
	while (++x < WIDTH)
	{
		map->camera_x = (2 * x) / ((double)WIDTH - 1);
		map->ray_dir.x = map->dir.x + (map->plane.x * map->camera_x);
		map->ray_dir.y = map->dir.y + (map->plane.y * map->camera_x);
		init_map_vars(map);
		get_step_and_side_dist(map);
		printf("mapx = %d || posx = %f\n", map->map_x, map->pos.x);
		printf("mapy = %d || posy = %f\n", map->map_y, map->pos.y);
		printf("ray_dir x = %f\n", map->ray_dir.x);
		printf("ray_dir y = %f\n", map->ray_dir.y);
		printf("delta_dist x = %f\n", map->delta_dist.x);
		printf("delta_dist y = %f\n", map->delta_dist.y);
		printf("side_dist x = %f\n", map->side_dist.x);
		printf("side_dist y = %f\n", map->side_dist.y);
		draw_lines_dda(map, cube);
		get_dist_to_wall(map);
		printf("wall dist = %f\n", map->wall_dist);
		get_wall_height(map);
		printf("wall height = %d\n", map->wall_height);
		set_wall_color(game, map, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
}
