/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:26:38 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/08 17:03:33 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (false);
		i++;
	}

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_format(int height, int width)
{
	(void) height;
	return (width);
}

bool	check_items(char **map, int height, int width)
{
	int	count_e;
	int	count_c;
	int	count_p;
	int	i;
	int	j;

	count_e = 0;
	count_c = 0;
	count_p = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j] == 'P')
				count_p++;
			if (map[i][j] == 'C')
				count_c++;
			if (map[i][j] == 'E')
				count_e++;
		}
	}
	return (count_p == 1 && count_c >= 1 && count_e == 1);
}

bool	check_outliers(char **map, int height, int width)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	check_the_map(char **map, int height, int width)
{
	if (!check_format(height, width))
		exit_with_error(map, "Invalid map format; ensure all rows are equal.\n");
	if (!check_walls(map, height, width))
		exit_with_error(map, "Map must be enclosed on all sides.\n");
	if (!check_outliers(map, height, width))
		exit_with_error(map, "Unknown symbol(s) in the map.\n");
	if (!check_items(map, height, width))
		exit_with_error(map, "Must have 1 Player, 1 Exit && at least 1 Item.\n");
	if (!check_path(map, height, width))
		exit_with_error(map, "invalid path.\n");
}
