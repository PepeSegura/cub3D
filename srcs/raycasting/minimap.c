#include "cub3d.h"
#include "defines.h"
#include "mlx.h"
#include "structures.h"

/* void	draw_minimap(t_mlx *mlx) */
/* { */
/* 	int	i; */
/* 	int	j; */

/* } */

void	draw_mm_base(t_mlx *mlx, int h, int w)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = SCREEN_WIDTH - MINIMAP_SIZE - 10;
	y = 10;
	i = x;
	while (i < x + w)
	{
		j = y;
		while (j < y + h)
		{
			my_mlx_pixel_put(mlx, i, j, 0x00000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
