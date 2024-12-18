/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:58:38 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/08 18:57:38 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_the_matrix(t_data *data)
{
	mlx_loop_hook(data->mlx, &render_map, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win, 17, 0, &free_data, data);
	mlx_loop(data->mlx);
}

int	key_press(int keysym, t_data *data)
{
	(void) keysym;
	if (keysym == XK_Escape)
		free_data(data);
	if (keysym == XK_w)
		move(data, -1, 0);
	if (keysym == XK_s)
		move(data, 1, 0);
	if (keysym == XK_a)
		move(data, 0, -1);
	if (keysym == XK_d)
		move(data, 0, 1);
	return (0);
}
