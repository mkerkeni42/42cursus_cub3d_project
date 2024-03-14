/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:59:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/14 14:15:19 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_handlerror(int x)
{
	if (x == 0)
		printf("Error\nWrong number of arguments\n");
	if (x == 1)
		printf("Error\nWrong number of elements\n");
	if (x == 2)
		printf("Error\nFile not found\n");
	if (x == 3)
		printf("Error\nColor does not exist\n");
	if (x == 4)
		printf("Error\nOnly numbers are expected for RGB\n");
	if (x == 5)
		printf("Error\n3 parameters are expected for RGB\n");
	if (x == 6)
		printf("Error\nBad characters\n");
	exit(1);
}

int	main(int ac,char **av)
{
	t_cube	cube;
	t_game	game;
	
	if (ac != 2)
		ft_handlerror(0);
	parsing(&cube, av[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, HEIGHT, WIDTH, "Cub3D");
	raycasting(&game, &cube);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
