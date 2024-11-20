/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:12:24 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/14 14:11:04 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int	check_file(char *path)
{
	int		fd;
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\n Invalid file extension.\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n No such file or directory.\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	**get_data(int fd)
{
	char	**map;
	char	buffer[BUFFER_SIZE];
	char	*data;
	char	*temp;
	int		data_bytes;

	data = ft_strdup("");
	data_bytes = read(fd, buffer, BUFFER_SIZE);
	while (data_bytes > 0)
	{
		buffer[data_bytes] = '\0';
		temp = data;
		data = ft_strjoin(data, buffer);
		free(temp);
		if (!data)
			return (NULL);
		data_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (data_bytes == -1)
		return (free(data), NULL);
	close(fd);
	if (data[0] == '\0')
		return (free(data), NULL);
	map = ft_split(data, '\n');
	return (free(data), map);
}

char	**get_map(char *path)
{
	int		fd;
	char	**map;

	fd = check_file(path);
	map = get_data(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		height;
	int		width;
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("This program takes 1 argument: a .ber file.\n", 1);
		return (-1);
	}
	map = get_map(argv[1]);
	if (!map)
		exit_with_error(map, "the file is empty.");
	height = get_height(map);
	width = get_width(map, height);
	check_the_map(map, height, width);
	data = malloc(sizeof(t_data));
	init_data(data, map, height, width);
	show_the_matrix(data);
	return (0);
}
