/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:47:30 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/22 13:57:14 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_value(int c, int x)
{
	if (x == 0 && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' \
		&& c != 'W')
		return (1);
	if (x == 1 && (c == ' ' || c == '\n' || c == '\0'))
		return (1);
	return (0);
}

static void	check_around(t_cube *cube, int i, int j)
{
	if (check_value(cube->map[i + 1][j], 1))
		ft_handlerror(7);
	if (check_value(cube->map[i - 1][j], 1))
		ft_handlerror(7);
	if (check_value(cube->map[i][j + 1], 1))
		ft_handlerror(7);
	if (check_value(cube->map[i][j - 1], 1))
		ft_handlerror(7);
}

void	check_map(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	cube->bool = 0;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			check_pos(cube, cube->map[i][j]);
			if (check_value(cube->map[i][j], 0) && cube->map[i][j] != ' ' \
				&& cube->map[i][j] != '\n')
				ft_handlerror(6);
			if (cube->map[i][j] != '1' && cube->map[i][j] != ' ' \
				&& cube->map[i][j] != '\n')
				check_around(cube, i, j);
		}
	}
	if (cube->bool == 0)
		ft_handlerror(10);
}

void	cpy_map(t_cube *cube)
{
	int	j;

	cube->map = malloc(sizeof(char *) * (cube->nb_line - cube->i + 1));
	j = -1;
	while (cube->file[cube->i])
	{
		cube->map[++j] = malloc(sizeof(char) \
			* (ft_strlen(cube->file[cube->i]) + 1));
		cube->map[j] = ft_strcpy(cube->map[j], cube->file[cube->i]);
		cube->i++;
	}
	cube->map[j + 1] = '\0';
	check_map(cube);
}

void	check_file(t_cube *cube)
{
	int	j;

	while (cube->file[++cube->i])
	{
		j = -1;
		while (cube->file[cube->i][++j])
		{
			if (cube->file[cube->i][j] != ' ' \
				&& check_value(cube->file[cube->i][j], 0) \
					&& cube->file[cube->i][j] != '\n')
				ft_handlerror(6);
			if (cube->file[cube->i][j] == '1')
			{
				cpy_map(cube);
				return ;
			}
		}
	}
}
