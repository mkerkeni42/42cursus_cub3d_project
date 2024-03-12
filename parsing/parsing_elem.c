/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:22:39 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/11 10:50:28 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_elem(t_cube *cube)
{
	cube->no = 0;
	cube->so = 0;
	cube->we = 0;
	cube->ea = 0;
	cube->f = 0;
	cube->c = 0;
}

static int	check_double(t_cube *cube, char *str)
{
	if (!ft_strcmp(str, "NO"))
		cube->no++;
	else if (!ft_strcmp(str, "SO"))
		cube->so++;
	else if (!ft_strcmp(str, "WE"))
		cube->we++;
	else if (!ft_strcmp(str, "EA"))
		cube->ea++;
	else if (!ft_strcmp(str, "F"))
		cube->f++;
	else if (!ft_strcmp(str, "C"))
		cube->c++;
	if (cube->no > 1 || cube->so > 1 || cube->we > 1 || cube->ea > 1 \
		|| cube->f > 1 || cube->c > 1)
		return (1);
	return (0);
}

static int	pars_elem(t_cube *cube)
{
	char	**tmp;

	tmp = ft_split(cube->file[cube->i], ' ');
	if (!ft_strncmp(tmp[0], "NO", ft_strlen(tmp[0])))
		return (check_double(cube, "NO"));
	else if (!ft_strncmp(tmp[0], "SO", ft_strlen(tmp[0])))
		return (check_double(cube, "SO"));
	else if (!ft_strncmp(tmp[0], "WE", ft_strlen(tmp[0])))
		return (check_double(cube, "WE"));
	else if (!ft_strncmp(tmp[0], "EA", ft_strlen(tmp[0])))
		return (check_double(cube, "EA"));
	else if (!ft_strncmp(tmp[0], "F", ft_strlen(tmp[0])))
		return (check_double(cube, "F"));
	else if (!ft_strncmp(tmp[0], "C", ft_strlen(tmp[0])))
		return (check_double(cube, "C"));
	return (1);
}

void	cpy_elem(t_cube *cube)
{
	int	j;

	cube->elem = malloc(sizeof(char *) * 7);
	j = -1;
	cube->i = -1;
	set_elem(cube);
	while (j != 5 && cube->file[++cube->i])
	{
		if (!pars_elem(cube))
		{
			cube->elem[++j] = malloc(sizeof(char) \
				* (ft_strlen(cube->file[cube->i]) + 1));
			cube->elem[j] = ft_strcpy(cube->elem[j], cube->file[cube->i]);
		}
	}
	cube->elem[j] = NULL;
	if (j != 5)
		ft_handlerror(1);
	check_param(cube);
	cpy_map(cube);
}
