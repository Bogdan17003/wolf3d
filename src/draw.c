/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:00:59 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/26 17:02:09 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_dot(t_mlx *mlx, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x >= (int)WIDTH || y >= (int)HEIGHT))
		mlx->img_ptr[x + y * (int)WIDTH] = color;
}

void	draw_flour(t_line *line, t_mlx *mlx, int x)
{
	line->drawstart--;
	while (++line->drawstart < HEIGHT)
		draw_dot(mlx, x, line->drawstart, 0x4f4f4f);
}

void	drawing(int x, t_line *line, t_mlx *mlx, t_camera *camera)
{
	while (line->drawstart < line->drawend)
	{
		line->d = line->drawstart * 256 - HEIGHT * 128 + line->lineheight * 128;
		line->texy = line->d * 64 / line->lineheight / 256;
		if (camera->side == 1 && camera->raydiry < 0)
			line->color = (mlx->player->map->texture[(line->texnum +
			mlx->player->texture_mod) % 8]->img_ptr[64 * line->texy +
			line->texx] >> 1) & 0x7F7F7F;
		if (camera->side == 1 && camera->raydiry > 0)
			line->color = (mlx->player->map->texture[(line->texnum + 1 +
			mlx->player->texture_mod) % 8]->img_ptr[64 * line->texy +
			line->texx] >> 1) & 0x7F7F7F;
		if (camera->side == 0 && camera->raydirx < 0)
			line->color = mlx->player->map->texture[(line->texnum + 2 +
			mlx->player->texture_mod) % 8]->img_ptr[64 * line->texy +
			line->texx];
		if (camera->side == 0 && camera->raydirx > 0)
			line->color = mlx->player->map->texture[(line->texnum + 3 +
			mlx->player->texture_mod) % 8]->img_ptr[64 * line->texy +
			line->texx];
		draw_dot(mlx, x, line->drawstart, line->color);
		line->drawstart++;
	}
	draw_flour(line, mlx, x);
}

void	drawline(t_mlx *mlx, t_camera *camera, t_map *map, int x)
{
	t_line	*line;

	if (!(line = (t_line *)ft_memalloc(sizeof(t_line))))
		write_error();
	line->lineheight = (int)(HEIGHT / camera->perpwalldist);
	line->drawstart = -line->lineheight / 2 + HEIGHT / 2;
	if (line->drawstart < 0)
		line->drawstart = 0;
	line->drawend = line->lineheight / 2 + HEIGHT / 2;
	if (line->drawend >= HEIGHT)
		line->drawend = HEIGHT - 1;
	texture_calculation(line, mlx, camera, map);
	drawing(x, line, mlx, camera);
	free(line);
}

void	drawmap(t_map *map)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		write_error();
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, (int)WIDTH, HEIGHT, "wolf3d");
	mlx->img = mlx_new_image(mlx->mlx, (int)WIDTH, (int)HEIGHT);
	mlx->img_ptr = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl,
																&mlx->ending);
	if (!(mlx->player = (t_player *)ft_memalloc(sizeof(t_player))))
		write_error();
	initialization_player(mlx->player, map);
	gameplay(mlx, mlx->player, map);
	mlx_hook(mlx->window, 2, 0, hook_keydown, mlx);
	mlx_hook(mlx->window, 3, 0, hook_release, mlx);
	mlx_hook(mlx->window, 17, 0, hook_close, mlx);
	mlx_loop_hook(mlx->mlx, move_or_rotate, mlx);
	mlx_loop(mlx->mlx);
}
