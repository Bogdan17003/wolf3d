/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:56:35 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/26 17:59:26 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hook_close(t_mlx *mlx)
{
	(void)mlx;
	system("leaks -q wolf3d");
	exit(EXIT_SUCCESS);
	return (0);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		(void)mlx;
		system("leaks -q wolf3d");
		exit(EXIT_SUCCESS);
	}
	if (key == 48 && !mlx->press_up && !mlx->press_down && !mlx->press_left &&
															!mlx->press_right)
	{
		mlx->player->texture_mod = (mlx->player->texture_mod + 1) % 8;
		gameplay(mlx, mlx->player, mlx->player->map);
	}
	if (key == 46)
	{
		mlx->player->move_mod = (mlx->player->move_mod + 1) % 3;
		mlx->press_up = 0;
		mlx->press_down = 0;
		mlx->press_right = 0;
		mlx->press_left = 0;
	}
	if (key == 257)
		mlx->player->turbo_mod = 1;
	hook_keydown_move(key, mlx);
	return (0);
}

int		hook_keydown_move(int key, t_mlx *mlx)
{
	if ((key == 126 && mlx->player->move_mod == 0) ||
		(key == 13 && (mlx->player->move_mod == 1 ||
						mlx->player->move_mod == 2)))
		mlx->press_up = 1;
	if ((key == 125 && mlx->player->move_mod == 0) ||
		(key == 1 && (mlx->player->move_mod == 1 ||
					mlx->player->move_mod == 2)))
		mlx->press_down = 1;
	if ((key == 124 && mlx->player->move_mod == 0) ||
		(key == 2 && mlx->player->move_mod == 1) ||
		(key == 14 && mlx->player->move_mod == 2))
		mlx->press_right = 1;
	if ((key == 123 && mlx->player->move_mod == 0) ||
		(key == 0 && mlx->player->move_mod == 1) ||
		(key == 12 && mlx->player->move_mod == 2))
		mlx->press_left = 1;
	return (0);
}

int		hook_release(int key, t_mlx *mlx)
{
	if ((key == 126 && mlx->player->move_mod == 0) ||
		(key == 13 && (mlx->player->move_mod == 1 ||
						mlx->player->move_mod == 2)))
		mlx->press_up = 0;
	if ((key == 125 && mlx->player->move_mod == 0) ||
		(key == 1 && (mlx->player->move_mod == 1 ||
					mlx->player->move_mod == 2)))
		mlx->press_down = 0;
	if ((key == 124 && mlx->player->move_mod == 0) ||
		(key == 2 && mlx->player->move_mod == 1) ||
		(key == 14 && mlx->player->move_mod == 2))
		mlx->press_right = 0;
	if ((key == 123 && mlx->player->move_mod == 0) ||
		(key == 0 && mlx->player->move_mod == 1) ||
		(key == 12 && mlx->player->move_mod == 2))
		mlx->press_left = 0;
	if (key == 257)
		mlx->player->turbo_mod = 0;
	return (0);
}
