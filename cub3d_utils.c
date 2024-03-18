/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:39:24 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/18 10:28:46 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit_game(t_game *game, int x)
{
	if (x == 1)
		write(2, "The path of your image is wrong !\n", 35);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	print_array(char **array)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			write(1, &array[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_handlerror(int x)
{
	if (x == 0)
		write(2, "Error\nWrong number of arguments !\n", 35);
	if (x == 1)
		write(2, "Error\nWrong number of elements !\n", 34);
	if (x == 2)
		write(2, "Error\nFile not found !\n", 24);
	if (x == 3)
		write(2, "Error\nColor does not exist !\n", 30);
	if (x == 4)
		write(2, "Error\nOnly numbers are expected for RGB !\n", 43);
	if (x == 5)
		write(2, "Error\n3 parameters are expected for RGB !\n", 43);
	if (x == 6)
		write(2, "Error\nBad characters !\n", 24);
	if (x == 7)
		write(2, "Error\nMap is not closed !\n", 27);
	if (x == 8)
		write(2, "Error\nThere is more than one position !\n", 41);
	if (x == 9)
		write(2, "Error\nWrong file name extension !\n", 35);
	if (x == 10)
		write(2, "Error\nThere is no start position !\n", 36);
	exit(EXIT_FAILURE);
}
