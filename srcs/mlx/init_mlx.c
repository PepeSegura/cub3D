/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:09:39 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/05 19:01:12 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	imgs_init(t_mlx *mlx)
{
	mlx->tex_north.img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->c.texture.north, &mlx->x, &mlx->y);
	mlx->tex_south.img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->c.texture.south, &mlx->x, &mlx->y);
	mlx->tex_east.img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->c.texture.east, &mlx->x, &mlx->y);
	mlx->tex_west.img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->c.texture.west, &mlx->x, &mlx->y);
	mlx->tex_north.addr = mlx_get_data_addr(mlx->tex_north.img,
			&mlx->tex_north.bits_per_pixel, &mlx->tex_north.line_length,
			&mlx->tex_north.endian);
	mlx->tex_south.addr = mlx_get_data_addr(mlx->tex_south.img,
			&mlx->tex_south.bits_per_pixel, &mlx->tex_south.line_length,
			&mlx->tex_south.endian);
	mlx->tex_east.addr = mlx_get_data_addr(mlx->tex_east.img,
			&mlx->tex_east.bits_per_pixel, &mlx->tex_east.line_length,
			&mlx->tex_east.endian);
	mlx->tex_west.addr = mlx_get_data_addr(mlx->tex_west.img,
			&mlx->tex_west.bits_per_pixel, &mlx->tex_west.line_length,
			&mlx->tex_west.endian);
}

/*  								X and Y Start Position
	mlx->pos_y = 3.5;  				
	mlx->dir_x = 0; 		N [-1] 		W [0] 		E [0] 		S [1]
	mlx->dir_y = -1;  		N [0] 		W [-1] 		E [1] 		S [0]
	mlx->plan_x = -0.66;	N [0] 		W [-0.66] 	E [0.66] 	S [0]
	mlx->plane_y = 0; 		N [0.66] 	W [0] 		E [0] 		S [-0.66]
*/
void	cube_init(t_mlx *mlx)
{
	mlx->win_w = SCREEN_WIDTH;
	mlx->win_h = SCREEN_HEIGHT;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "cub3D");
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	mlx->map.width = 0;
	mlx->map.height = 0;
	mlx->map.max_alt = 0;
	mlx->map.xyzc = NULL;
	mlx->multiplicator = 1;
	mlx->multi_z = 500;
	mlx->pos_x = 2.5;
	mlx->pos_y = 3.5;
	mlx->dir_x = 0;
	mlx->dir_y = -1;
	mlx->teta = 0;
	mlx->plan_x = -0.66;
	mlx->plane_y = 0;
	mlx->x = 64;
	mlx->y = 64;
	imgs_init(mlx);
}
