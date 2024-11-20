/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:14:53 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/14 14:15:03 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int y_change, int x_change)
{
	t_loc	p;
	int		x_new;
	int		y_new;
	char	value;

	p = get_player_loc(data->map, data->map_height, data->map_width);
	y_new = p.y + y_change;
	x_new = p.x + x_change;
	value = data->map[y_new][x_new];
	if (value == '1')
		return ;
	if (value == 'E')
	{
		if (no_items(data->map, data->map_height, data->map_width))
		{
			print_moves(data);
			game_over(data);
		}
	}
	if (value == '0' || value == 'C')
	{
		data->map[y_new][x_new] = 'P';
		data->map[p.y][p.x] = '0';
		print_moves(data);
	}
}

void	print_moves(t_data *data)
{
	data->count++;
	ft_putnbr_fd(data->count, 1);
	ft_putstr_fd(" moves \n", 1);
}

void	game_over(t_data *data)
{
	ft_putstr_fd("Congratulations, you've escaped the Matrix.\n", 1);
	ft_putstr_fd("Welcome to the real world!\n", 1);
	free_data(data);
}

bool	no_items(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
