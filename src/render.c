/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:52:22 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/08 18:49:54 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, char **map, int height, int width)
{
	int		len;

	len = 50;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width * len, height * len, "so_long");
	data->count = 0;
	data->tile_size = len;
	data->map = map;
	data->map_height = height;
	data->map_width = width;
	data->wall = get_image(data->mlx, "./rsrc/wall.xpm", len);
	data->space = get_image(data->mlx, "./rsrc/space.xpm", len);
	data->item = get_image(data->mlx, "./rsrc/pill.xpm", len);
	data->player = get_image(data->mlx, "./rsrc/neo.xpm", len);
	data->exit = get_image(data->mlx, "./rsrc/exit.xpm", len);
}

void	*get_image(void *mlx, char *file_path, int size)
{
	return (mlx_xpm_file_to_image(mlx, file_path, &size, &size));
}

int	render_map(t_data *data)
{
	int		i;
	int		j;
	t_loc	loc;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			loc.x = j * data->tile_size;
			loc.y = i * data->tile_size;
			if (data->map[i][j] == '1')
				set_image(data, data->wall, loc.x, loc.y);
			else if (data->map[i][j] == '0')
				set_image(data, data->space, loc.x, loc.y);
			else if (data->map[i][j] == 'P')
				set_image(data, data->player, loc.x, loc.y);
			else if (data->map[i][j] == 'E')
				set_image(data, data->exit, loc.x, loc.y);
			else if (data->map[i][j] == 'C')
				set_image(data, data->item, loc.x, loc.y);
		}
	}
	return (0);
}

void	set_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}
