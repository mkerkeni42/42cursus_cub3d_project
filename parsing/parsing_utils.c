/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:59:49 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/18 11:00:57 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int count_comma(char *str)
{
	int i;
	int count;
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			count++;
	}
	return (count);
}
