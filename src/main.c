/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:06:30 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/26 17:32:48 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2 || ft_strcmp(argv[0], "./wolf3d") != 0 ||
						ft_strlen(argv[1]) <= 5 || !ft_strstr(argv[1], ".wolf"))
		write_error();
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		write_error();
	map->len_ver = 0;
	map->len_hor = 0;
	if (check_read(fd = open(argv[1], O_RDONLY), map))
		write_error();
	close(fd);
	malloc_memory(map);
	read_and_add(fd = open(argv[1], O_RDONLY), map);
	drawmap(map);
	return (0);
}
