/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:46:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/21 11:52:17 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_pixels(t_game *game, int color, int x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		if (x == 0)
		{
			j = HEIGHT / 2 - 1;
			while (++j < HEIGHT)
				my_pixel_put(game, i, j, color);
		}
		else
			while (++j < HEIGHT / 2)
				my_pixel_put(game, i, j, color);
	}
}

void	set_floor_color(t_game *game)
{
	t_color	rgb;
	int		color;

	rgb.red = game->cube->floor[0];
	rgb.green = game->cube->floor[1];
	rgb.blue = game->cube->floor[2];
	color = get_color(rgb.red, rgb.green, rgb.blue);
	draw_pixels(game, color, 0);
}

void	set_ceiling_color(t_game *game)
{
	t_color	rgb;
	int		color;

	rgb.red = game->cube->ceiling[0];
	rgb.green = game->cube->ceiling[1];
	rgb.blue = game->cube->ceiling[2];
	color = get_color(rgb.red, rgb.green, rgb.blue);
	draw_pixels(game, color, 1);
}
