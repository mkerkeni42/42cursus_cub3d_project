/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:59:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/22 15:12:50 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_name(char *file_name)
{
	char	*dot;

	dot = ft_strchr(file_name, '.');
	if (!dot)
		return (1);
	if (ft_strlen(dot) != 4)
		return (1);
	else
		if (dot[1] != 'c' || dot[2] != 'u' || dot[3] != 'b')
			return (1);
	return (0);
}

static void	remove_nl(char **array)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
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
	j = -1;
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

static void	init_vars(t_game *game)
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
	cpy_cub(&cube, av[1]);
	remove_nl(cube.map);
	remove_nl(cube.elem);
	game.map = &map;
	game.cube = &cube;
	get_texture_file(&game);
	map.card_point = cube.pos;
	init_vars(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3D");
	get_textures(&game);
	raycasting(&game);
	mlx_hook(game.win, 2, 1L << 0, &deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_loop(game.mlx);
	free_tab_struct(&cube);
	return (0);
}
