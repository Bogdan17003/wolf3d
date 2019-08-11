/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:46:33 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/18 16:11:15 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		search_other_chars(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '0')
			return (1);
		str++;
	}
	return (0);
}

int		check_map(char *str, int *check_line, t_map *map)
{
	int		n;

	n = 0;
	if (*str < '1' || *str > '9')
		return (1);
	while (*str)
	{
		if (*str >= '1' && *str <= '9')
			n++;
		if (n == map->len_hor && (*(str + 1) == '\0'))
			(*check_line)--;
		if (n == map->len_hor && (*(str + 1) != '\0'))
			return (1);
		if (*str == '0' && (*(str + 1) == '\0'))
			return (1);
		str++;
	}
	return (0);
}
