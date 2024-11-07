/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:52:22 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/07 04:11:40 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, char **map, int height, int width)
{
	int		size;
	void	*win;
	void	*mlx;

	size = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width * size, height * size, "so_long");
	data->mlx = mlx;
	data->win = win;
	data->tile_size = size;
	data->map = map;
	data->map_height = height;
	data->map_width = width;
	data->wall = get_image(data->mlx, "./rsrc/wall.xpm", size);
	data->space = get_image(data->mlx, "./rsrc/space.xpm", size);
	data->item = get_image(data->mlx, "./rsrc/pill.xpm", size);
	data->player = get_image(data->mlx, "./rsrc/neo.xpm", size);
	data->exit = get_image(data->mlx, "./rsrc/exit.xpm", size);
}

void	*get_image(void *mlx, char *file_path, int size)
{
	return (mlx_xpm_file_to_image(mlx, file_path, &size, &size));
}

void	render_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			x = j * data->tile_size;
			y = i * data->tile_size;
			if (data->map[i][j] == '1')
				set_image(data, data->wall, x, y);
			else if (data->map[i][j] == '0')
				set_image(data, data->space, x, y);
			else if (data->map[i][j] == 'P')
				set_image(data, data->player, x, y);
			else if (data->map[i][j] == 'E')
				set_image(data, data->exit, x, y);
			else if (data->map[i][j] == 'C')
				set_image(data, data->item, x, y);
		}
	}
}

void	set_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

void	show_map(t_data *data, char **map, int height, int width)
{
	(void) data;
	(void) map;
	(void) height;
	(void) width;
	//void *mlx_win = mlx_new_window()
}