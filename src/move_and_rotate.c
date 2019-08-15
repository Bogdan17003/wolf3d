/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:50:12 by bdeomin           #+#    #+#             */
/*   Updated: 2019/08/15 20:21:51 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move(t_mlx *mlx, double distance)
{
	if (distance < 0)
		mlx->press_down = 1;
	else
		mlx->press_up = 1;
	if (mlx->player->map->file_map[(int)(mlx->player->posx + mlx->player->dirx
							* 2 * distance)][(int)(mlx->player->posy)] == 0)
		mlx->player->posx += mlx->player->dirx * distance;
	if (mlx->player->map->file_map[(int)(mlx->player->posx)][(int)(mlx->
						player->posy + mlx->player->diry * 2 * distance)] == 0)
		mlx->player->posy += mlx->player->diry * distance;
}

void	rotate(t_mlx *mlx, double angle)
{
	double olddirx;
	double oldplanex;

	if (angle < 0)
		mlx->press_right = 1;
	else
		mlx->press_left = 1;
	olddirx = mlx->player->dirx;
	mlx->player->dirx = mlx->player->dirx * cos(angle) - mlx->player->diry *
																	sin(angle);
	mlx->player->diry = olddirx * sin(angle) + mlx->player->diry *
																	cos(angle);
	oldplanex = mlx->player->planex;
	mlx->player->planex = mlx->player->planex * cos(angle) -
											mlx->player->planey * sin(angle);
	mlx->player->planey = oldplanex * sin(angle) + mlx->player->planey *
																	cos(angle);
}

int		move_or_rotate(t_mlx *mlx)
{
	double	angle;
	double	speed;

	if (!mlx->press_up && !mlx->press_down && !mlx->press_left &&
															!mlx->press_right)
		return (0);
	angle = 3.0f / 180.0f * M_PI;
	speed = 0.19f;
	if (mlx->press_up || mlx->press_down)
		angle *= 1.3;
	if (mlx->player->turbo_mod)
		speed *= 1.7;
	if (mlx->press_up)
		move(mlx, speed);
	if (mlx->press_down)
		move(mlx, -speed);
	if (mlx->press_right)
		rotate(mlx, -angle);
	if (mlx->press_left)
		rotate(mlx, angle);
	ft_bzero(mlx->img_ptr, (int)WIDTH * (int)HEIGHT * 4);
	gameplay(mlx, mlx->player, mlx->player->map);
	return (0);
}
