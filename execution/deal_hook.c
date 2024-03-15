/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:32:32 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/15 12:45:05 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*void	go_up(t_game *game)
{
	//  if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false)
	//  	posX += dirX * moveSpeed; 
}

void	go_down(t_game *game)
{
	
}

void	go_right(t_game *game)
{
	
}

void	go_left(t_game *game)
{
	
}*/

int	deal_key(int key, t_game *game)
{
	if (key == 65307)
		ft_exit_game(game, 0);
	/*else if (key == 65362)
		go_up(game);
	else if (key == 65364)
		go_down(game);
	else if (key == 65363)
		go_right(game);
	else if (key == 65361)
		go_left(game);*/
	return (0);
}
