/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:59:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/18 15:38:30 by mkerkeni         ###   ########.fr       */
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
	{
		if (dot[1] != 'c' || dot[2] != 'u' || dot[3] != 'b')
			return (1);
	}
	return (0);
}

static void	remove_nl_map(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (cube->map[++i])
	{
		j = 0;
		while (cube->map[i][j] && cube->map[i][j] != '\n')
			j++;
		if (cube->map[i][j] == '\n')
			cube->map[i][j] = '\0';
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
	remove_nl_map(&cube);
	map.card_point = cube.pos;
	map.pos.x = (double)get_pos(&cube, 0);
	map.pos.y = (double)get_pos(&cube, 1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, HEIGHT, WIDTH, "Cub3D");
	raycasting(&game, &map, &cube);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_loop(game.mlx);
	free_tab_struct(&cube);
	return (0);
}
