/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:19:51 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/25 14:33:42 by ykifadji         ###   ########.fr       */
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

static int	get_pixel_color(t_texture text, int x, int y)
{
	char	*color;

	color = text.addr + (y * text.line_len + x * (text.bit_per_pixel / 8));
	return (*(unsigned int *)color);
}

void	draw_vertical_lines(t_game *game, t_map *map, int x)
{
	int	y;
	int	color;

	y = map->draw_start;
	while (y <= map->draw_end)
	{
		map->tex_y = (int)map->tex_pos & (game->tex_height - 1);
		map->tex_pos += map->step;
		color = get_pixel_color(find_texture(game), map->tex_x, map->tex_y);
		
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
