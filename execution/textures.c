/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:30:15 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/22 09:15:15 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture_file(t_game *game)
{
	int	i;	

	i = -1;
	while (game->cube->elem[++i])
	{
		if (game->cube->elem[i][0] != 'F' && game->cube->elem[i][0] != 'C')
			game->textures[i] = ft_strdup(game->cube->elem[i]); 
	}
}

void	get_textures(t_game *game)
{
	int	i;

	i = -1;
	while (game->textures[++i])
	{
		if (game->textures[i][0] == 'N')
		{
			game->no = mlx_xpm_file_to_image(game->img_data, \
			ft_strchr(game->textures[i], '.'), (int *)64, \
			(int *)64);
		}
		else if ((game->textures[i][0] == 'S'))
		{
			game->so = mlx_xpm_file_to_image(game->img_data, \
				ft_strchr(game->textures[i], '.'), &game->tex_width, \
				&game->tex_height);
		}
		else if ((game->textures[i][0] == 'E'))
		{
			game->ea = mlx_xpm_file_to_image(game->img_data, \
				ft_strchr(game->textures[i], '.'), &game->tex_width, \
				&game->tex_height);
		}
		else if ((game->textures[i][0] == 'W'))
		{
			game->we = mlx_xpm_file_to_image(game->img_data, \
				ft_strchr(game->textures[i], '.'), &game->tex_width, \
				&game->tex_height);
		}
	}
}

int	draw_textures(char *texture)
{
	int	x;
	int	y;
	int	color;
	t_color	rgb;
	int	pixel_index;
	
	x = -1;
	while(++x < 64)
	{
		y = -1;
		while(++y < 64)
		{
			pixel_index = (y * 64 + x) * 4;
			rgb.red = texture[pixel_index + 2];
			rgb.green = texture[pixel_index + 1];
			rgb.blue = texture[pixel_index];
			color = get_color(rgb.red, rgb.green, rgb.blue);
		}
	}
	return (color);
}