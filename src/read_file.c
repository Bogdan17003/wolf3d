/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:47:58 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/19 14:57:37 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_read(int fd, t_map *map)
{
	char	*str;
	int		check_len;
	int		check_line;
	int		check_bad;

	check_line = 2;
	check_bad = 0;
	while (get_next_line(fd, &str) == 1)
	{
		(map->len_ver)++;
		check_len = ft_strlen(str);
		if ((map->len_hor != 0 && map->len_hor != check_len) ||
																check_line == 0)
			check_bad = 1;
		else if (map->len_hor == 0)
			map->len_hor = check_len;
		if (search_other_chars(str) || check_map(str, &check_line, map))
			check_bad = 1;
		free(str);
		if (check_line == 2 || check_bad)
			return (1);
	}
	if (check_line != 0 || map->len_hor <= 2 || map->len_ver <= 2)
		return (1);
	return (0);
}

void	new_position(t_map *map, int *position, int i, int j)
{
	map->positionx = i;
	map->positiony = j;
	*position = *position - 1;
}

void	read_and_add(int fd, t_map *map)
{
	char	*str;
	char	*ptr;
	int		i;
	int		j;
	int		position;

	i = -1;
	position = 1;
	while (get_next_line(fd, &str) == 1)
	{
		ptr = str;
		i++;
		j = -1;
		while (*str)
		{
			j++;
			if (position && *str == '0')
				new_position(map, &position, i, j);
			map->file_map[i][j] = *str - 48;
			str++;
		}
		free(ptr);
	}
}
