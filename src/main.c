
#include  "so_long.h"

int check_file(char *path)
{
	int		fd;
	size_t	len;

	len = ft_strlen(path);

	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\n Invalid file extension\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
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
	map = ft_split(data, '\n');
	free(data);
	return (map);
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
		return (-1);
	map = get_map(argv[1]);
	height = get_height(map);
	width = get_width(map, height);
	check_the_map(map, height, width);
	data = malloc(sizeof(t_data));
	init_data(data, map, height, width);
	render_map(data);
	mlx_loop(data->mlx);
	free_map(map);
}
