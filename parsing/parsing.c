/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:47:07 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/09 15:09:32 by ykifadji         ###   ########.fr       */
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
		ft_handlerror(3);
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
		ft_handlerror(3);
	i = 0;
	cube->file[i] = get_next_line(fd);
	while (cube->file[i])
		cube->file[++i] = get_next_line(fd);
	close(fd);
}

void	parsing(t_cube *cube, char *av)
{
//	int	i;

	//i = -1;
	cpy_cub(cube, av);
	cpy_elem(cube);
	
	// while (cube->elem[++i])
	// 	printf("%s", cube->elem[i]);
}
