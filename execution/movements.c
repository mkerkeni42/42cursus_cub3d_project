/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:15:29 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/22 15:12:35 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	go_front(t_game *game)
{
	if (game->cube->map[(int)game->map->pos.y][(int)(game->map->pos.x + \
		game->map->dir.x * 0.2)] != '1')
		game->map->pos.x += game->map->dir.x * 0.2;
	if (game->cube->map[(int)(game->map->pos.y + game->map->dir.y * \
		0.2)][(int)game->map->pos.x] != '1')
		game->map->pos.y += game->map->dir.y * 0.2;
}

void	go_back(t_game *game)
{
	if (game->cube->map[(int)game->map->pos.y][(int)(game->map->pos.x - \
		game->map->dir.x * 0.2)] != '1')
		game->map->pos.x -= game->map->dir.x * 0.2;
	if (game->cube->map[(int)(game->map->pos.y - game->map->dir.y * \
		0.2)][(int)game->map->pos.x] != '1')
		game->map->pos.y -= game->map->dir.y * 0.2;
}

void	go_right(t_game *game)
{
	if (game->cube->map[(int)game->map->pos.y][(int)(game->map->pos.x - \
		game->map->dir.y * 0.2)] != '1')
		game->map->pos.x -= game->map->dir.y * 0.2;
	if (game->cube->map[(int)(game->map->pos.y + game->map->dir.x * \
		0.2)][(int)game->map->pos.x] != '1')
		game->map->pos.y += game->map->dir.x * 0.2;
}

void	go_left(t_game *game)
{
	if (game->cube->map[(int)game->map->pos.y][(int)(game->map->pos.x + \
		game->map->dir.y * 0.2)] != '1')
		game->map->pos.x += game->map->dir.y * 0.2;
	if (game->cube->map[(int)(game->map->pos.y - game->map->dir.x * \
		0.2)][(int)game->map->pos.x] != '1')
		game->map->pos.y -= game->map->dir.x * 0.2;
}
