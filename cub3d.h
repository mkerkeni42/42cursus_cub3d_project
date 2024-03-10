/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:00:05 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/09 15:07:36 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H

#include "./Libft/inc/libft.h"
#include "./Libft/inc/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

typedef struct s_cube {
	char	**map;
	char	**file;
	char	**elem;
	int		nb_line;
	int		i;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
}			t_cube;

void	ft_handlerror(int x);

/*=========================PARSING=========================*/

void	parsing(t_cube *cube, char *av);
void	cpy_elem(t_cube *cube);
void	check_param(t_cube *cube);
void	cpy_map(t_cube *cube);

#endif