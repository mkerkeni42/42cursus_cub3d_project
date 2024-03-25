/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:59:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/25 14:49:32 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_name(char *file_name)
{
	char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot)
		return (1);
	if (ft_strlen(dot) != 4)
		return (1);
	else
		if (dot[1] != 'c' || dot[2] != 'u' || dot[3] != 'b')
			return (1);
	return (0);
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
