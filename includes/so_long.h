/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:46 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/08 18:36:26 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
# include<stdio.h>
# include<stdbool.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
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
	int		count;
}	t_data;

typedef struct s_location
{
	int	x;
	int	y;
}	t_loc;

typedef struct s_map_size
{
	int	height;
	int	width;
}	t_size;

/****************************CHECK.C*************************/
void	check_the_map(char **map, int height, int width);
bool	check_format(int height, int width);
bool	check_walls(char **map, int height, int width);
bool	check_outliers(char **map, int height, int width);
bool	check_items(char **map, int height, int width);
/*****************************UTILE.C**********************/
int		get_height(char **map);
int		get_width(char **map, int height);
/*************************** FREE.C*****************************/
void	free_map(char **map);
int		free_data(t_data *data);
void	exit_with_error(char **map, char *error);
/**************************RENDER.C*****************************/
void	init_data(t_data *data, char **map, int height, int width);
void	*get_image(void *mlx, char *file_path, int size);
int		render_map(t_data *data);
void	set_image(t_data *data, void *img, int x, int y);
/************************FLOD_FILL.C********************************/
bool	check_path(char **map, int height, int width);
void	flood_fill(char **map, int x, int y, t_size map_size);
char	**copy_map(char **map, int height);
bool	is_valid(char **map, int height, int width);
t_loc	get_player_loc(char **map, int height, int width);
/************************MATRIX.C*********************************/
void	show_the_matrix(t_data *data);
int		key_press(int keysym, t_data *data);
/***************************MOVES.C************************** */
void	move(t_data *data, int y_change, int x_change);
bool	no_items(char **map, int height, int width);
void	win_game(t_data *data);
void	print_moves(t_data *data);
#endif