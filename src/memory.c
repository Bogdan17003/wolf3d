/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:43:15 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/20 17:30:04 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	malloc_memory(t_map *map)
{
	int	i;

	i = -1;
	if (!(map->file_map = (int **)ft_memalloc(map->len_ver * sizeof(int*))))
		write_error();
	while (++i < map->len_ver)
		if (!(map->file_map[i] = (int *)ft_memalloc(map->len_hor *
																sizeof(int))))
		{
			while (i--)
				free(map->file_map[i]);
			free(map->file_map);
			write_error();
		}
	i = -1;
	if (!(map->texture = (t_texture **)ft_memalloc(8 * sizeof(t_texture *))))
		write_error();
	while (++i < 8)
		if (!(map->texture[i] = (t_texture *)ft_memalloc(sizeof(t_texture))))
		{
			while (i--)
				free(map->file_map[i]);
			free(map->file_map);
			write_error();
		}
}

void	free_memory(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->len_ver)
		free(map->file_map[i]);
	free(map->file_map);
	i = -1;
	while (++i < 8)
		free(map->texture[i]);
	free(map->texture);
}
