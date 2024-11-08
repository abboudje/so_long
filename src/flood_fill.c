/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:58:19 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/08 16:21:46 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_path(char **map, int height, int width)
{
	char	**mapy;
	t_loc	location;
	t_size	map_size;
	bool	valid;

	mapy = copy_map(map, height);
	location = get_player_loc(map, height, width);
	map_size.height = height;
	map_size.width = width;
	flood_fill(mapy, location.x, location.y, map_size);
	valid = is_valid(mapy, height, width);
	free_map(mapy);
	return (valid);
}

bool	is_valid(char **map, int height, int width)
{
	int		i;
	int		j;
	char	value;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			value = map[i][j];
			if (value == 'P' || value == 'E' || value == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}


void	flood_fill(char **map, int x, int y, t_size map_size)
{
	if (x < 0 || y < 0 || x >= map_size.width || y >= map_size.height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, map_size);
	flood_fill(map, x - 1, y, map_size);
	flood_fill(map, x, y + 1, map_size);
	flood_fill(map, x, y - 1, map_size);
}

t_loc	get_player_loc(char **map, int height, int width)
{
	t_loc	location;

	location.y = 0;
	while (location.y < height)
	{
		location.x = 0;
		while (location.x < width)
		{
			if (map[location.y][location.x] == 'P')
				return (location);
			location.x++;
		}
		location.y++;
	}
	return (location);
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		exit_with_error(map, "Memory allocation failed");
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			exit_with_error(map, "Memory allocation failed");
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}
