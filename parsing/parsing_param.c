/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:19:56 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/12 16:34:04 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_color_arr(t_cube *cube, char **line, int x)
{
	int		i;
	int		j;
	int		k;
	char	tmp[4];

	if (line[0][0] == 'F')
		x = 0;
	else if (line[0][0] == 'C')
		x = 1;
	i = -1;
	while (line[++i])
	{
		j = -1;
		k = -1;
		while (line[i][++j])
		{
			if (ft_isdigit(line[i][j]))
				tmp[++k] = line[i][j];
		}
		tmp[k + 1] = '\0';
		if (x == 0)
			cube->floor[i] = ft_atoi(tmp);
		else if (x == 1)
			cube->ceiling[i] = ft_atoi(tmp);
	}
}

static int	check_value(char *rgb)
{
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	while (rgb[++i])
	{
		if (nb > 1 && rgb[i] == ' ')
			ft_handlerror(4);
		if ((rgb[i] == ' ' && i == 1) || rgb[i] == '\n' \
			|| (rgb[i] == 'F' && i == 0) || (rgb[i] == 'C' && i == 0))
			continue ;
		if (!ft_isdigit(rgb[i]))
			ft_handlerror(4);
		else if (ft_isdigit(rgb[i]))
			nb++;
	}
	return (nb);
}

void	check_rgb(char **rgb)
{
	int		i;
	int		nb;

	i = -1;
	while (rgb[++i])
	{
		if (i == 0 && (ft_strlen(rgb[i]) < 3 || ft_atoi(rgb[i] + 2) > 255))
			ft_handlerror(3);
		nb = check_value(rgb[i]);
		if (nb > 3 || ft_atoi(rgb[i]) > 255)
			ft_handlerror(3);
	}
	if (i != 3)
		ft_handlerror(5);
}

void	check_path(char **elem, char *path)
{
	int		fd;
	char	*tmp;

	fd = -1;
	tmp = ft_malloc(sizeof(char) * ft_strlen(path) + 1); // ici j'ai rajoute le + 1 pour le \0
	while (path[++fd] && path[fd] != '\n')
		tmp[fd] = path[fd];
	tmp[fd] = '\0';
	if (file_name(tmp))
		ft_handlerror(2);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		free_array(elem);
		ft_handlerror(2);
	}
	close(fd);
	free(tmp);
}

void	check_param(t_cube *cube)
{
	char	**tmp;
	int		i;

	i = -1;
	while (cube->elem[++i])
	{
		tmp = ft_split(cube->elem[i], ' ');
		if (ft_strlen(tmp[0]) == 2)
		{
			check_path(tmp, tmp[1]);
			free_array(tmp);
		}
		else
		{
			free_array(tmp);
			tmp = ft_split(cube->elem[i], ',');
			check_rgb(tmp);
			get_color_arr(cube, tmp, 0);
			free_array(tmp);
		}
	}
}
