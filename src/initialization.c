/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:07:52 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/26 16:43:17 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initialization_player(t_player *player, t_map *map)
{
	player->posx = map->positionx + 0.5;
	player->posy = map->positiony + 0.5;
	player->dirx = -1 * cos(180.0f / 180.0f * M_PI);
	player->diry = -1 * sin(180.0f / 180.0f * M_PI);
	player->planex = 0.66 * sin(180.0f / 180.0f * M_PI);
	player->planey = 0.66 * cos(180.0f / 180.0f * M_PI);
	player->texture_mod = 0;
	player->move_mod = 0;
	player->turbo_mod = 0;
	player->map = map;
}

void	initc_x(t_camera *camera, int step, double sidedist)
{
	camera->stepx = step;
	camera->sidedistx = sidedist;
}

void	initc_y(t_camera *camera, int step, double sidedist)
{
	camera->stepy = step;
	camera->sidedisty = sidedist;
}

void	initialization_camera(t_player *player, t_camera *camera, int x)
{
	camera->camerax = 2 * x / (double)(WIDTH) - 1;
	camera->raydirx = player->dirx + player->planex * camera->camerax;
	camera->raydiry = player->diry + player->planey * camera->camerax;
	camera->mapx = (int)player->posx;
	camera->mapy = (int)player->posy;
	camera->sidedistx = 0;
	camera->sidedisty = 0;
	camera->deltadistx = fabs(1 / camera->raydirx);
	camera->deltadisty = fabs(1 / camera->raydiry);
	camera->perpwalldist = 0;
	camera->stepx = 0;
	camera->stepy = 0;
	camera->hit = 0;
	camera->side = 0;
	if (camera->raydirx < 0)
		initc_x(camera, -1, (player->posx - camera->mapx) * camera->deltadistx);
	else
		initc_x(camera, 1, (camera->mapx + 1.0 - player->posx) *
															camera->deltadistx);
	if (camera->raydiry < 0)
		initc_y(camera, -1, (player->posy - camera->mapy) * camera->deltadisty);
	else
		initc_y(camera, 1, (camera->mapy + 1.0 - player->posy) *
															camera->deltadisty);
}
