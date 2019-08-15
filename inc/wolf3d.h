/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:09:31 by bdeomin           #+#    #+#             */
/*   Updated: 2019/08/15 20:20:45 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define HEIGHT 900
# define WIDTH	1200

# define OPT_COUNT 4

# include <OpenCL/opencl.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <time.h>

typedef	struct	s_texture
{
	void		*img;
	int			*img_ptr;
	int			bpp;
	int			sl;
	int			ending;
}				t_texture;

typedef struct	s_map
{
	double		positionx;
	double		positiony;
	int			len_ver;
	int			len_hor;
	int			**file_map;
	t_texture	**texture;
}				t_map;

typedef	struct	s_player
{
	double		posx;
	double		posy;

	double		dirx;
	double		diry;

	double		planex;
	double		planey;

	double		frametime;

	double		movespeed;
	double		rotspeed;

	int			texture_mod;
	int			move_mod;
	int			turbo_mod;

	t_map		*map;
}				t_player;

typedef	struct	s_camera
{
	double		camerax;
	double		raydirx;
	double		raydiry;

	int			mapx;
	int			mapy;

	double		sidedistx;
	double		sidedisty;

	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;

	int			stepx;
	int			stepy;

	int			hit;
	int			side;
}				t_camera;

typedef	struct	s_line
{
	int			lineheight;
	int			drawstart;
	int			drawend;

	int			texnum;
	double		wallx;
	int			texx;
	int			texy;

	int			d;

	int			color;
}				t_line;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*window;
	void		*img;
	int			*img_ptr;
	int			bpp;
	int			sl;
	int			ending;

	int			press_up;
	int			press_down;
	int			press_left;
	int			press_right;

	t_player	*player;
}				t_mlx;

int				search_other_chars(char *str);
int				check_map(char *str, int *check_line, t_map *map);

void			draw_dot(t_mlx *mlx, int x, int y, int color);
void			drawing(int x, t_line *line, t_mlx *mlx, t_camera *camera);
void			draw_flour(t_line *line, t_mlx *mlx, int x);
void			drawline(t_mlx *mlx, t_camera *camera, t_map *map, int x);
void			drawmap(t_map *map);

void			calculate_height_line(t_camera *camera, t_map *map);
void			gameplay(t_mlx *mlx, t_player *player, t_map *map);

int				hook_close(t_mlx *mlx);
int				hook_keydown(int key, t_mlx *mlx);
int				hook_keydown_move(int key, t_mlx *mlx);
int				hook_release(int key, t_mlx *mlx);

void			initialization_player(t_player *player, t_map *map);
void			initialization_camera(t_player *player, t_camera *camera,
																	int x);

void			write_error(void);

void			malloc_memory(t_map *map);
void			free_memory(t_map *map);

void			move(t_mlx *mlx, double distance);
void			rotate(t_mlx *mlx, double angle);
int				move_or_rotate(t_mlx *mlx);

int				check_read(int fd, t_map *map);
void			read_and_add(int fd, t_map *map);

void			initialization_texture(t_texture **texture, t_mlx *mlx);
void			texture_calculation(t_line *line, t_mlx *mlx, t_camera *camera,
																	t_map *map);

#endif
