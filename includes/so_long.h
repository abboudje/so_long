/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:46 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/06 16:23:17 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
# include<stdio.h>
# include<stdbool.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../core/libft/libft.h"
# define BUFFER_SIZE 300

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*space;
	void	*item;
	void	*exit;
	void	*player;
	int		tile_size;
	char	**map;
	int		map_width;
	int		map_height;
}	t_data;

/****************************CHECK.C*************************/
void	check_the_map(char **map, int height, int width);
bool	check_format(int height, int width);
bool	check_walls(char **map, int height, int width);
bool	check_outliers(char **map, int height, int width);
bool	check_items(char **map, int height, int width);
/*****************************MATRIX.C**********************/
int		get_height(char **map);
int		get_width(char **map, int height);
/*************************** FREE.C*****************************/
void	free_map(char **map);
void	exit_with_error(char **map, char *error);
/**************************RENDER.C*****************************/
void	show_map(t_data *data, char **map, int height, int width);
void	init_data(t_data *data, char **map, int height, int width);
void	*get_image(void *mlx, char *file_path, int size);
void	render_map(t_data *data);
void	set_image(t_data *data, void *img, int x, int y);

#endif