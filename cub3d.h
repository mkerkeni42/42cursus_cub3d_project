/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:00:05 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/12 15:41:39 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H_

# include "./Libft/inc/libft.h"
# include "./Libft/inc/get_next_line.h"
# include "./minilibx-linux/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define HEIGHT 1280
# define WIDTH 1024

typedef struct	s_map
{
	double		camera_x;
	double		rayDir_x;
	double		rayDir_y;
	//wich box of the mp we are int
	int 		map_x;
	int			map_y;
	//length of ray from current position to nex x or y side
	double		sideDist_x;
	double		sideDist_y;
	//length of ray from one x or y side to next x or y side
	double		DeltaDist_x;
	double		DeltaDist_y;
	double		perpWallDist;
	//what direction to step in x or y direction (either +1 or -1)
	int			step_x;
	int			step_y;
	
	int			hit; //was there a wall hit ?
	int			side; // was a NS or a EW wall hit?
}				t_map;

typedef struct s_cube
{
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

typedef struct	s_vector
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_vector;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_vector	pos;
	double		time;
	double		old_time;
}				t_game;

void	ft_handlerror(int x);

/*=========================PARSING=========================*/

void	parsing(t_cube *cube, char *av);
void	cpy_elem(t_cube *cube);
void	check_param(t_cube *cube);
void	cpy_map(t_cube *cube);

int		deal_key(int key, t_game *game);
int		ft_exit_game(t_game *game, int x);

void	draw_lines_dda(t_game *game, t_map *map, t_cube *cube);
void	get_dist_to_wall(t_game *game, t_map *map, t_cube *cube);
void	get_wall_height(t_game *game, t_map *map, t_cube *cube);

#endif
