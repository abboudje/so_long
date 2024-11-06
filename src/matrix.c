/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:01:22 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/06 00:32:07 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_width(char **map, int height)
{
	int	i;
	int	width;

	width = ft_strlen(map[0]);
	i = 1;
	while (i < height)
	{
		if (width != (int) ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (width);
}
