/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:49:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/26 17:02:16 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture_calculation(t_line *line, t_mlx *mlx, t_camera *camera,
																	t_map *map)
{
	line->texnum = map->file_map[camera->mapx][camera->mapy] - 1;
	if (camera->side == 0)
		line->wallx = mlx->player->posy + camera->perpwalldist *
																camera->raydiry;
	else
		line->wallx = mlx->player->posx + camera->perpwalldist *
																camera->raydirx;
	line->wallx -= floor((line->wallx));
	line->texx = (int)(line->wallx * 64);
	if (camera->side == 0 && camera->raydirx > 0)
		line->texx = 64 - line->texx - 1;
	if (camera->side == 1 && camera->raydiry < 0)
		line->texx = 64 - line->texx - 1;
}

void	get_addr_textures(t_texture **texture)
{
	texture[0]->img_ptr = (int *)mlx_get_data_addr(texture[0]->img,
						&texture[0]->bpp, &texture[0]->sl, &texture[0]->ending);
	texture[1]->img_ptr = (int *)mlx_get_data_addr(texture[1]->img,
						&texture[1]->bpp, &texture[1]->sl, &texture[1]->ending);
	texture[2]->img_ptr = (int *)mlx_get_data_addr(texture[2]->img,
						&texture[2]->bpp, &texture[2]->sl, &texture[2]->ending);
	texture[3]->img_ptr = (int *)mlx_get_data_addr(texture[3]->img,
						&texture[3]->bpp, &texture[3]->sl, &texture[3]->ending);
	texture[4]->img_ptr = (int *)mlx_get_data_addr(texture[4]->img,
						&texture[4]->bpp, &texture[4]->sl, &texture[4]->ending);
	texture[5]->img_ptr = (int *)mlx_get_data_addr(texture[5]->img,
						&texture[5]->bpp, &texture[5]->sl, &texture[5]->ending);
	texture[6]->img_ptr = (int *)mlx_get_data_addr(texture[6]->img,
						&texture[6]->bpp, &texture[6]->sl, &texture[6]->ending);
	texture[7]->img_ptr = (int *)mlx_get_data_addr(texture[7]->img,
						&texture[7]->bpp, &texture[7]->sl, &texture[7]->ending);
}

void	initialization_texture(t_texture **texture, t_mlx *mlx)
{
	int size;

	size = 64;
	if (!(texture[0]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/bluestone.xpm", &size, &size)) ||
	!(texture[1]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/colorstone.xpm", &size, &size)) ||
	!(texture[2]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/eagle.xpm", &size, &size)) ||
	!(texture[3]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/greystone.xpm", &size, &size)) ||
	!(texture[4]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/mossy.xpm", &size, &size)) ||
	!(texture[5]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/purplstone.xpm", &size, &size)) ||
	!(texture[6]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/redbrick.xpm", &size, &size)) ||
	!(texture[7]->img = mlx_xpm_file_to_image(mlx->mlx,
								"textures/wood.xpm", &size, &size)))
		write_error();
	get_addr_textures(texture);
}
