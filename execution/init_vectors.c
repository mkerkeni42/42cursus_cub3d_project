/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:37:28 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/18 15:30:15 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_dir(t_map *map)
{
	if (map->card_point == 'N')
	{
		map->dir.x = 0;
		map->dir.y = -1;
	}
	else if (map->card_point == 'S')
	{
		map->dir.x = 0;
		map->dir.y = 1;
	}
	else if (map->card_point == 'W')
	{
		map->dir.x = -1;
		map->dir.y = 0;
	}
	else if (map->card_point == 'E')
	{
		map->dir.x = 1;
		map->dir.y = 0;
	}
}

void	init_plane(t_map *map)
{
	if (map->card_point == 'N')
	{
		map->plane.x = 0.66;
		map->plane.y = 0;
	}
	else if (map->card_point == 'S')
	{
		map->plane.x = -0.66;
		map->plane.y = 0;
	}
	else if (map->card_point == 'W')
	{
		map->plane.x = 0;
		map->plane.y = -0.66;
	}
	else if (map->card_point == 'E')
	{
		map->plane.x = 0;
		map->plane.y = 0.66;
	}
}
