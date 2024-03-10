/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:47:30 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/10 16:37:39 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != ' ' \
				&& cube->map[i][j] != '\n' && cube->map[i][j] != '0' \
					&& cube->map[i][j] != 'N' && cube->map[i][j] != 'S' \
						&& cube->map[i][j] != 'E' && cube->map[i][j] != 'W')
				ft_handlerror(6);
		}
	}
}

void	cpy_map(t_cube *cube)
{
	int	j;

	cube->map = malloc(sizeof(char *) * (cube->nb_line - cube->i + 1));
	j = -1;
	while (cube->file[++cube->i])
	{
		cube->map[++j] = malloc(sizeof(char) \
			* (ft_strlen(cube->file[cube->i]) + 1));
		cube->map[j] = ft_strcpy(cube->map[j], cube->file[cube->i]);
	}
	check_map(cube);
}
