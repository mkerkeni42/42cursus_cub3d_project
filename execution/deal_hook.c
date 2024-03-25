/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:32:32 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/24 15:04:51 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	rot_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->map->dir.x;
	game->map->dir.x = game->map->dir.x * cos(0.2) - game->map->dir.y * \
	sin(0.2);
	game->map->dir.y = old_dir_x * sin(0.2) + game->map->dir.y * cos(0.2);
	old_plane_x = game->map->plane.x;
	game->map->plane.x = game->map->plane.x * cos(0.2) - game->map->plane.y * \
	sin(0.2);
	game->map->plane.y = old_plane_x * sin(0.2) + game->map->plane.y * cos(0.2);
}

static void	rot_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->map->dir.x;
	old_plane_x = game->map->plane.x;
	game->map->dir.x = game->map->dir.x * cos(-0.2) - game->map->dir.y * \
	sin(-0.2);
	game->map->dir.y = old_dir_x * sin(-0.2) + game->map->dir.y * cos(-0.2);
	game->map->plane.x = game->map->plane.x * cos(-0.2) - game->map->plane.y * \
	sin(-0.2);
	game->map->plane.y = old_plane_x * sin(-0.2) + game->map->plane.y * \
	cos(-0.2);
}

int	deal_key(int key, t_game *game)
{
	if (key == ESC)
		ft_exit_game(game, 0);
	else if (key == FRONT)
		go_front(game);
	else if (key == BACK)
		go_back(game);
	else if (key == RIGHT)
		go_right(game);
	else if (key == LEFT)
		go_left(game);
	else if (key == ROT_RIGHT)
		rot_right(game);
	else if (key == ROT_LEFT)
		rot_left(game);
	raycasting(game);
	return (0);
}
