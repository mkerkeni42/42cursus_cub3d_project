/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:59:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/04/15 22:13:18 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	get_texture_file(game);
	game->map->card_point = game->cube->pos;
	init_vars(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	get_textures(game);
	raycasting(game);
	mlx_hook(game->win, 2, 1L << 0, &deal_key, game);
	mlx_hook(game->win, 17, 0, ft_exit_game, game);
	mlx_loop(game->mlx);
}

void	remove_nl(char **array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		j = 0;
		while (array[i][j] && array[i][j] != '\n')
			j++;
		if (array[i][j] == '\n')
			array[i][j] = '\0';
	}
}

static int	get_pos(t_cube *cube, int x)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (cube->map[i][j] == cube->pos)
			{
				if (x == 0)
					return (j);
				else
					return (i);
			}
		}
	}
	return (EXIT_FAILURE);
}

void	init_vars(t_game *game)
{
	game->tex_height = 64;
	game->tex_width = 64;
	game->map->pos.x = (double)get_pos(game->cube, 0) + 0.5;
	game->map->pos.y = (double)get_pos(game->cube, 1) + 0.5;
	init_dir(game->map);
	init_plane(game->map);
}

int	main(int ac, char **av)
{
	t_cube	cube;
	t_game	game;
	t_map	map;

	if (ac != 2)
		ft_handlerror(0);
	if (check_file_name(av[1]))
		ft_handlerror(9);
	parsing(&cube, av[1]);
	game.map = &map;
	game.cube = &cube;
	init_game(&game);
	free_tab_struct(&cube);
	return (0);
}
