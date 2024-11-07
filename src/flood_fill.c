/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:58:19 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/07 14:34:30 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_path(char **map, int height, int width)
{
	char	**mapy;
	t_loc	location;

	mapy = copy_map(map, height);
	location = get_start_position(map, height, width);
	flood_fill(mapy, location, height, width);
}

void	flood_fill(char **map, t_loc p, int height, int width)
{
	if (p.x < 0 || p.y < 0 || p.x >= width || p.y >= height)
		return ;
	if (map[p.y][p.x] == '1' || map[p.y][p.x] == 'V')
		return ;
    map[p.y][p.x] = 'V';
    flood_fill(map, p.x + 1, p.y); // Right
    flood_fill(map, p.x - 1, p.y); // Left
    flood_fill(map, p.x, p.y + 1); // Down
    flood_fill(map, p.x, p.y - 1); // Up
}

t_loc	get_start_position(char **map, int height, int width)
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

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		exit_with_error(map, "Probleme in Malloc");
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			exit_with_error(map, "Probleme in Malloc");
			return (NULL);
		}
		i++;
	}
	return (copy);
}
