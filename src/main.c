
#include  "so_long.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_win;
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "hello world!");
	img.img = mlx_new_image(mlx, 50, 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int i = -1;
	while (++i < 50)
	{
		int j = -1;
		while (++j < 50)
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 50, 50);
	mlx_loop(mlx);
	//mlx_loop(mlx);
}