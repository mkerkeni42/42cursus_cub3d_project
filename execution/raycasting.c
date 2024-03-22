/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:59:33 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/21 15:42:09 by ykifadji         ###   ########.fr       */
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
	if (map->ray_dir.x == 0)
		map->delta_dist.x = 1e30;
	else
		map->delta_dist.x = fabs(1 / map->ray_dir.x);
	if (map->ray_dir.y == 0)
		map->delta_dist.y = 1e30;
	else
		map->delta_dist.y = fabs(1 / map->ray_dir.y);
}

void	raycasting(t_game *game)
{
	int	x;

	x = -1;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img_data = mlx_get_data_addr(game->img, \
	&game->bits_per_pixel, &game->size_line, &game->endian);
	set_floor_color(game);
	set_ceiling_color(game);
	while (++x < WIDTH)
	{
		game->map->camera_x = 2 * x / (double)WIDTH - 1;
		game->map->ray_dir.x = game->map->dir.x + game->map->plane.x * \
		game->map->camera_x;
		game->map->ray_dir.y = game->map->dir.y + game->map->plane.y * \
		game->map->camera_x;
		init_map_vars(game->map);
		get_step_and_side_dist(game->map);
		draw_lines_dda(game->map, game->cube);
		get_dist_to_wall(game->map);
		get_wall_height(game->map);
		draw_vertical_lines(game, game->map, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
}
