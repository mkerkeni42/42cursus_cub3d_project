/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:00:05 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/15 14:30:57 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./Libft/inc/libft.h"
# include "./Libft/inc/get_next_line.h"
# include "./minilibx-linux/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define HEIGHT 1320
# define WIDTH 720

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_map
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		camera_x;
	t_vector	ray_dir;
	//wich box of the mp we are int
	int			map_x;
	int			map_y;
	//length of ray from current position to nex x or y side
	t_vector	side_dist;
	//length of ray from one x or y side to next x or y side
	t_vector	delta_dist;
	double		wall_dist;
	//what direction to step in x or y direction (either +1 or -1)
	int			step_x;
	int			step_y;
	int			hit; //was there a wall hit ?
	int			side; // was a NS or a EW wall hit?
	int			wall_height;
	int			draw_start;
	int			draw_end;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_game;

typedef struct s_cube
{
	char	**map;
	char	**file;
	char	**elem;
	int		floor[3];
	int		ceiling[3];
	int		nb_line;
	int		i;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	char	pos;
}			t_cube;

/*=========================PARSING=========================*/

void	cpy_cub(t_cube *cube, char *av);
void	cpy_elem(t_cube *cube);
void	check_param(t_cube *cube);
void	cpy_map(t_cube *cube);
void	check_file(t_cube *cube);

/*==========================UTILS==========================*/

int		ft_exit_game(t_game *game, int x);
void	ft_handlerror(int x);
void	free_array(char **array);
void	print_array(char **array);

/*========================EXECUTION========================*/

int		deal_key(int key, t_game *game);

void	raycasting(t_game *game, t_map *map, t_cube *cube);
void	draw_lines_dda(t_map *map, t_cube *cube);
void	get_dist_to_wall(t_map *map);
void	get_wall_height(t_map *map);
void	set_wall_color(t_game *game, t_map *map, int x);
int		get_color(int red, int green, int blue);
void	draw_vertical_lines(t_game *game, t_map *map, int x, int color);

#endif
