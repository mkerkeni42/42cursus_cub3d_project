/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:00:05 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/03/22 15:00:45 by ykifadji         ###   ########.fr       */
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

# define HEIGHT 720
# define WIDTH 1320

# define ESC 65307
# define ROT_RIGHT 65361
# define ROT_LEFT 65363
# define FRONT 119
# define BACK 115
# define LEFT 97
# define RIGHT 100

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}				t_texture;

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
	int			map_x;
	int			map_y;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			wall_height;
	int			draw_start;
	int			draw_end;
	char		card_point;
	double		wall_x;
	int			tex_num;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
}				t_map;

typedef struct s_cube
{
	char	**map;
	char	**file;
	char	**elem;
	int		floor[3];
	int		ceiling[3];
	int		nb_line;
	int		bool;
	int		i;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	char	pos;
}			t_cube;

typedef struct 	s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	unsigned int	*text_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*textures[5];
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	int				tex_width;
	int				tex_height;
	t_map			*map;
	t_cube			*cube;
}					t_game;

/*=========================PARSING=========================*/

void	cpy_cub(t_cube *cube, char *av);
void	cpy_elem(t_cube *cube);
void	check_param(t_cube *cube);
void	cpy_map(t_cube *cube);
void	check_file(t_cube *cube);
void	check_pos(t_cube *cube, int c);
void	free_tab_struct(t_cube *cube);
int		file_name(char *file_name);

/*==========================UTILS==========================*/

int		ft_exit_game(t_game *game, int x);
void	ft_handlerror(int x);
void	free_array(char **array);
void	print_array(char **array);

/*========================EXECUTION========================*/

int		deal_key(int key, t_game *game);
void	go_front(t_game *game);
void	go_back(t_game *game);
void	go_right(t_game *game);
void	go_left(t_game *game);

void	raycasting(t_game *game);
void	init_dir(t_map *map);
void	init_plane(t_map *map);

void	draw_lines_dda(t_map *map, t_cube *cube);
void	get_dist_to_wall(t_map *map);
void	get_wall_height(t_map *map);

void	set_floor_color(t_game *game);
void	set_ceiling_color(t_game *game);
void	my_pixel_put(t_game *game, int x, int y, int color);
int		get_color(int red, int green, int blue);
void	draw_vertical_lines(t_game *game, t_map *map, int x);

void		get_textures(t_game *game);
void		get_texture_file(t_game *game);
void		get_texture_coordinates(t_game *game, t_map *map);
t_texture	find_texture(t_game *game);

#endif
