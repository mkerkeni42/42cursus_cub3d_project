/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:30:15 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/04/12 11:04:29 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture_file(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->cube->elem[++i])
	{
		if (game->cube->elem[i][0] != 'F' && game->cube->elem[i][0] != 'C')
			game->textures[++j] = ft_strdup(game->cube->elem[i]);
	}
	game->textures[j + 1] = '\0';
}

static t_texture	get_texture_infos(t_game *game, char *path)
{
	t_texture	text;
	char		*start;
	int			end;
	char		*new_path;

	start = ft_strchr(path, '.');
	end = get_space_index(start);
	new_path = ft_substr(start, 0, end);
	text.img = mlx_xpm_file_to_image(game->mlx, \
		new_path, &text.x, &text.y);
	text.addr = mlx_get_data_addr(text.img, &(text.bit_per_pixel), \
		&(text.line_len), &(text.endian));
	free(new_path);
	return (text);
}

void	get_textures(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->textures[++i])
	{
		j = 0;
		while (game->textures[i][j] && game->textures[i][j] == ' ')
			j++;
		if ((game->textures[i][j] == 'S'))
			game->so = get_texture_infos(game, game->textures[i]);
		else if (game->textures[i][j] == 'N')
			game->no = get_texture_infos(game, game->textures[i]);
		else if ((game->textures[i][j] == 'E'))
			game->ea = get_texture_infos(game, game->textures[i]);
		else if ((game->textures[i][j] == 'W'))
			game->we = get_texture_infos(game, game->textures[i]);
	}
}

void	get_texture_coordinates(t_game *game, t_map *map)
{
	if (map->side == 0)
		map->wall_x = map->pos.y + map->wall_dist * map->ray_dir.y;
	else
		map->wall_x = map->pos.x + map->wall_dist * map->ray_dir.x;
	map->wall_x -= floor(map->wall_x);
	map->tex_x = (int)(map->wall_x *(double)game->tex_width);
	if (map->side == 0 && map->ray_dir.x > 0)
		map->tex_x = game->tex_width - map->tex_x - 1;
	if (map->side == 1 && map->ray_dir.y < 0)
		map->tex_x = game->tex_width - map->tex_x - 1;
	map->step = 1.0 * game->tex_height / map->wall_height;
	map->tex_pos = (map->draw_start - HEIGHT / 2 + map->wall_height / 2) \
		* map->step;
}

t_texture	find_texture(t_game *game)
{
	if (game->map->side == 0 && game->map->pos.x < game->map->map_x)
		return (game->ea);
	else if (game->map->side == 0 && game->map->pos.x > game->map->map_x)
		return (game->we);
	else if (game->map->side == 1 && game->map->pos.y > game->map->map_y)
		return (game->no);
	else if (game->map->side == 1 && game->map->pos.y < game->map->map_y)
		return (game->so);
	return (game->no);
}
