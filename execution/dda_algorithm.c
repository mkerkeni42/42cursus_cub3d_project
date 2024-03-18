/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:24:46 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/18 15:39:13 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_wall_height(t_map *map)
{
	map->wall_height = (int)(HEIGHT / map->wall_dist);
	map->draw_start = -map->wall_height / 2 + HEIGHT / 2;
	if (map->draw_start < 0)
		map->draw_start = 0;
	map->draw_end = map->wall_height / 2 + HEIGHT / 2;
	if (map->draw_end >= HEIGHT)
		map->draw_end = HEIGHT - 1;
}

void	get_dist_to_wall(t_map *map)
{
	if (map->side == 0)
		map->wall_dist = map->side_dist.x - map->delta_dist.x;
	else
		map->wall_dist = map->side_dist.y - map->delta_dist.y;
}

void	draw_lines_dda(t_map *map, t_cube *cube)
{
	map->hit = 0;
	while (map->hit == 0)
	{
		if (map->side_dist.x < map->side_dist.y)
		{
			map->side_dist.x += map->delta_dist.x;
			map->map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->side_dist.y += map->delta_dist.y;
			map->map_y += map->step_y;
			map->side = 1;
		}
		if (cube->map[map->map_y][map->map_x] != '0')
			map->hit = 1;
	}
}
