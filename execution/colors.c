/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:19:51 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/19 12:55:20 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_pixel_put(t_game *game, int x, int y, int color)
{
	char	*pixel;

	pixel = game->img_data + (y * game->size_line + x \
	* (game->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	draw_vertical_lines(t_game *game, t_map *map, int x, int color)
{
	int	y;

	y = map->draw_start;
	while (y <= map->draw_end)
	{
		my_pixel_put(game, x, y, color);
		y++;
	}
}

int	get_color(int red, int green, int blue)
{
	t_color	rgb_color;
	int		color;	

	rgb_color.red = red;
	rgb_color.green = green;
	rgb_color.blue = blue;
	color = (rgb_color.red << 16) | (rgb_color.green << 8) | rgb_color.blue;
	return (color);
}

void	set_wall_color(t_game *game, t_map *map, int x)
{
	int	color;

	color = get_color(255, 0, 0);
	if (map->side == 1)
		color = color / 1.5;
	draw_vertical_lines(game, map, x, color);
}
