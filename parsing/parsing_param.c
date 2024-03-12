/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:19:56 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/12 13:40:59 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

long int	ft_atol(const char *str)
{
	int			i;
	long int	res;
	int			sign;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	check_rgb(char *tmp)
{
	char	**rgb;
	int		i;
	int		j;
	int		nb;

	rgb = ft_split(tmp, ',');
	i = -1;
	while (rgb[++i])
	{
		j = -1;
		nb = 0;
		while (rgb[i][++j])
		{
			if ((rgb[i][j] > 8 && rgb[i][j] < 14) || rgb[i][j] == 32)
				break ;
			if (!ft_isdigit(rgb[i][j]))
				ft_handlerror(4);
			else if (ft_isdigit(rgb[i][j]))
				nb++;
		}
		if (nb > 3 || ft_atol(rgb[i]) > 255)
			ft_handlerror(3);
	}
	if (i != 3)
		ft_handlerror(5);
}

void	check_path(char *path)
{
	int		fd;
	char	*tmp;

	fd = -1;
	tmp = malloc(sizeof(char) * ft_strlen(path));
	while (path[++fd] && path[fd] != '\n')
	{
		tmp[fd] = path[fd];
	}
	tmp[fd] = '\0';
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		ft_handlerror(2);
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
			check_path(tmp[1]);
		else
			check_rgb(tmp[1]);
	}
}
