/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:47:07 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/18 09:27:52 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	size_of_file(t_cube *cube, char *av)
{
	char	*str;
	int		fd;

	cube->nb_line = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_handlerror(2);
	str = get_next_line(fd);
	while (str)
	{
		cube->nb_line++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (cube->nb_line + 1);
}

void	cpy_cub(t_cube *cube, char *av)
{
	int	fd;
	int	i;

	cube->file = ft_calloc(sizeof(char *), size_of_file(cube, av));
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_handlerror(2);
	i = 0;
	cube->file[i] = get_next_line(fd);
	while (cube->file[i])
		cube->file[++i] = get_next_line(fd);
	close(fd);
	cpy_elem(cube);
}
