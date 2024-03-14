/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:59:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/12 15:16:30 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	ft_handlerror(int x)
{
	if (x == 0)
		printf("Error\nWrong number of arguments\n");
	if (x == 1)
		printf("Error\nWrong number of elements\n");
	if (x == 2)
		printf("Error\nFile not found\n");
	if (x == 3)
		printf("Error\nColor does not exist\n");
	if (x == 4)
		printf("Error\nOnly numbers are expected for RGB\n");
	if (x == 5)
		printf("Error\n3 parameters are expected for RGB\n");
	if (x == 6)
		printf("Error\nBad characters\n");
	if (x == 7)
		printf("Error\nMap is not closed");
	if (x == 8)
		printf("Error\nThere is more one position\n");
	exit(1);
}

int	main(int ac,char **av)
{
	t_cube	cube;
	
	if (ac != 2)
		ft_handlerror(0);
	cpy_cub(&cube, av[1]);
	return (0);
}
