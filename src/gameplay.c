/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:57:09 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/24 16:27:16 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calculate_height_line(t_camera *camera, t_map *map)
{
	while (camera->hit == 0)
	{
		if (camera->sidedistx < camera->sidedisty)
		{
			camera->sidedistx += camera->deltadistx;
			camera->mapx += camera->stepx;
			camera->side = 0;
		}
		else
		{
			camera->sidedisty += camera->deltadisty;
			camera->mapy += camera->stepy;
			camera->side = 1;
		}
		if (map->file_map[camera->mapx][camera->mapy] > 0)
			camera->hit = 1;
	}
}

void	gameplay(t_mlx *mlx, t_player *player, t_map *map)
{
	int			x;
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		write_error();
	x = -1;
	initialization_texture(map->texture, mlx);
	while (++x < WIDTH)
	{
		initialization_camera(player, camera, x);
		calculate_height_line(camera, map);
		if (camera->side == 0)
			camera->perpwalldist = (camera->mapx - player->posx +
								(1 - camera->stepx) / 2) / camera->raydirx;
		else
			camera->perpwalldist = (camera->mapy - player->posy +
								(1 - camera->stepy) / 2) / camera->raydiry;
		drawline(mlx, camera, map, x);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	free(camera);
}
