/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:19:51 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/14 15:20:11 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_lines(t_game *game, t_map * map, int x, int color)
{
	int	y;
	
	y = map->drawStart;
	while (y++ <= map->drawEnd)
		game->img_data[y * WIDTH + x] = color;
}

int	get_color(int red, int green, int blue)
{
	t_color	RGBcolor;
	int		color;	

	RGBcolor.red = red;
	RGBcolor.green = green;
	RGBcolor.blue = blue;
	color = (RGBcolor.red << 16) | (RGBcolor.green << 8) | RGBcolor.blue;
	return(color);	
}

void	set_wall_color(t_game *game, t_map *map, int x)
{
	int	color;

	color = get_color(255, 0, 0);
	if (map->side == 1)
		color = color / 2;
	draw_vertical_lines(game, map, x, color);	
}
