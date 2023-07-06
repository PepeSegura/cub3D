/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:09:39 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/06 14:14:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define IMG		0
#define ADDR	1

void	check_mlx_worked(t_mlx *mlx, int flag)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (flag == IMG && mlx->tex[i].img == NULL)
			ft_print_error("MLX couldn't open the img.");
		if (flag == ADDR && mlx->tex[i].addr == NULL)
			ft_print_error("MLX couldn't get the img address.");
		i++;
	}
}

void	all_xpm_to_img(t_mlx *mlx)
{
	mlx->tex[NORTH].img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data.texture.north, &mlx->x, &mlx->y);
	mlx->tex[SOUTH].img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data.texture.south, &mlx->x, &mlx->y);
	mlx->tex[EAST].img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data.texture.east, &mlx->x, &mlx->y);
	mlx->tex[WEST].img = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data.texture.west, &mlx->x, &mlx->y);
	check_mlx_worked(mlx, IMG);
}

void	all_img_data(t_mlx *mlx)
{
	mlx->tex[NORTH].addr = mlx_get_data_addr(mlx->tex[NORTH].img,
			&mlx->tex[NORTH].bits_per_pixel, &mlx->tex[NORTH].line_length,
			&mlx->tex[NORTH].endian);
	mlx->tex[SOUTH].addr = mlx_get_data_addr(mlx->tex[SOUTH].img,
			&mlx->tex[SOUTH].bits_per_pixel, &mlx->tex[SOUTH].line_length,
			&mlx->tex[SOUTH].endian);
	mlx->tex[EAST].addr = mlx_get_data_addr(mlx->tex[EAST].img,
			&mlx->tex[EAST].bits_per_pixel, &mlx->tex[EAST].line_length,
			&mlx->tex[EAST].endian);
	mlx->tex[WEST].addr = mlx_get_data_addr(mlx->tex[WEST].img,
			&mlx->tex[WEST].bits_per_pixel, &mlx->tex[WEST].line_length,
			&mlx->tex[WEST].endian);
	check_mlx_worked(mlx, ADDR);
}

/*  								X and Y Start Position
	mlx->pos_y = 3.5;  				
	mlx->dir_x = 0; 		N [-1] 		W [0] 		E [0] 		S [1]
	mlx->dir_y = -1;  		N [0] 		W [-1] 		E [1] 		S [0]
	mlx->plan_x = -0.66;	N [0] 		W [-0.66] 	E [0.66] 	S [0]
	mlx->plane_y = 0; 		N [0.66] 	W [0] 		E [0] 		S [-0.66]
*/

void	set_spawn(t_mlx *mlx)
{
	if (mlx->player.facing == 'N')
	{
		mlx->dir_x = -1;
		mlx->plane_y = 0.66;
	}
	if (mlx->player.facing == 'S')
	{
		mlx->dir_x = 1;
		mlx->plane_y = -0.66;
	}
	if (mlx->player.facing == 'E')
	{
		mlx->dir_y = 1;
		mlx->plan_x = 0.66;
	}
	if (mlx->player.facing == 'W')
	{
		mlx->dir_y = -1;
		mlx->plan_x = -0.66;
	}
}

void	cube_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	mlx->pos_x = (double)mlx->player.x + 0.5;
	mlx->pos_y = (double)mlx->player.y + 0.5;
	set_spawn(mlx);
	mlx->x = 64;
	mlx->y = 64;
	all_xpm_to_img(mlx);
	all_img_data(mlx);
}
