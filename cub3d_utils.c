/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:39:24 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/11 10:39:48 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit_game(t_game *game, int x)
{
	if (x == 1)
		write(2, "The path of your image is wrong !\n", 35);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
