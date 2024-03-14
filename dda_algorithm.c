/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:24:46 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/14 15:36:15 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	get_wall_height(t_game *game, t_map *map, t_cube *cube)
{
	map->wall_height = (int)(HEIGHT / map->perpWallDist);
	map->drawStart = -map->wall_height / 2 + HEIGHT / 2;
	if (map->drawStart < 0)
		map->drawStart = 0;
	map->drawEnd = map->wall_height / 2 + HEIGHT / 2;
	if (map->drawEnd >= HEIGHT)
		map->drawEnd = HEIGHT - 1;
}

void	get_dist_to_wall(t_game *game, t_map *map, t_cube *cube)
{
	if (map->side == 0)
		map->perpWallDist = map->sideDist_x - map->DeltaDist_x;
	else
		map->perpWallDist = map->sideDist_y - map->DeltaDist_y;
}

void	draw_lines_dda(t_game *game, t_map *map, t_cube *cube)
{
	while (map->hit == 0)
	{
		if (map->sideDist_x < map->sideDist_y)
		{
			map->sideDist_x += map->DeltaDist_x;
			map->map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->sideDist_y += map->DeltaDist_y;
			map->map_y += map->step_y;
			map->side = 1;
		}
		if (cube->map[map->map_x][map->map_y] > 0)
			map->hit = 1;
	}
}
