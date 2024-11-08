/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:05:04 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/08 18:36:03 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	free_data(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->space)
		mlx_destroy_image(data->mlx, data->space);
	if (data->item)
		mlx_destroy_image(data->mlx, data->item);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
	free(data);
	exit(0);
	return (0);
}

void	exit_with_error(char **map, char *error_message)
{
	free_map(map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}
