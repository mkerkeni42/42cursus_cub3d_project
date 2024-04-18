/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:19:56 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/18 10:37:28 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_color_arr(t_cube *cube, char **line, int x)
{
	int		i;

	if (line[0][0] == 'F')
		x = 0;
	else if (line[0][0] == 'C')
		x = 1;
	i = -1;
	while (line[++i])
	{
		if (i == 0)
		{
			if (x == 0)
				cube->floor[i] = ft_atoi(line[i] + 1);
			else if (x == 1)
				cube->ceiling[i] = ft_atoi(line[i] + 1);
		}
		else
		{
			if (x == 0)
				cube->floor[i] = ft_atoi(line[i]);
			else if (x == 1)
				cube->ceiling[i] = ft_atoi(line[i]);
		}
	}
	free_array(line);
}

static void	check_value(char *rgb)
{
	char	**tmp;
	int		i;
	int		j;

	if (!ft_strcmp(rgb, ""))
		ft_handlerror(0);
	if (rgb[0] && (rgb[0] == 'C' || rgb[0] == 'F'))
		if (rgb[1] != ' ')
			ft_handlerror(0);
	tmp = ft_split(rgb + 1, ' ');
	if (tmp && tmp[1])
	{
		free_array(tmp);
		ft_handlerror(0);
	}
	i = -1;
	while (tmp[++i])
	{
		j = -1;
		if (!ft_isdigit(tmp[i][++j]))
			ft_handlerror(4);
	}
	free_array(tmp);
}

void	check_rgb(t_cube *cube, char **rgb)
{
	int		i;

	i = -1;
	remove_nl(rgb);
	while (rgb[++i])
	{
		if (i == 0 && (ft_strlen(rgb[i]) < 3 || ft_atoi(rgb[i] + 2) > 255 \
			|| ft_atoi(rgb[i] + 2) < 0))
			ft_handlerror(3);
		check_value(rgb[i]);
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			ft_handlerror(3);
	}
	if (i != 3)
		ft_handlerror(5);
	get_color_arr(cube, rgb, 0);
}

void	check_path(char **elem, char *path)
{
	int		fd;
	char	*tmp;

	fd = -1;
	tmp = ft_malloc(sizeof(char) * ft_strlen(path) + 1);
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
	int		j;

	i = -1;
	j = 0;
	while (cube->elem[++i])
	{
		tmp = ft_split(cube->elem[i], ' ');
		if (ft_strlen(tmp[0]) == 2)
		{
			while (tmp[j])
				j++;
			if (j != 2)
				ft_handlerror(0);
			check_path(tmp, tmp[1]);
			free_array(tmp);
		}
		else
		{
			free_array(tmp);
			tmp = ft_split(cube->elem[i], ',');
			check_rgb(cube, tmp);
		}
	}
}
