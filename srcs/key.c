/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:39:54 by davgarci          #+#    #+#             */
/*   Updated: 2023/03/25 00:34:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_cam(int keycode, t_mlx *mlx, double old_dir_x, double old_plan_x)
{
	if (keycode == LEFT)
	{
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(ROT_MS) - mlx->dir_y * sin(ROT_MS);
		mlx->dir_y = old_dir_x * sin(ROT_MS) + mlx->dir_y * cos(ROT_MS);
		old_plan_x = mlx->plan_x;
		mlx->plan_x = mlx->plan_x * cos(ROT_MS) - mlx->plane_y * sin(ROT_MS);
		mlx->plane_y = old_plan_x * sin(ROT_MS) + mlx->plane_y * cos(ROT_MS);
	}
	if (keycode == RIGHT)
	{
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(-ROT_MS) - mlx->dir_y * sin(-ROT_MS);
		mlx->dir_y = old_dir_x * sin(-ROT_MS) + mlx->dir_y * cos(-ROT_MS);
		old_plan_x = mlx->plan_x;
		mlx->plan_x = mlx->plan_x * cos(-ROT_MS) - mlx->plane_y * sin(-ROT_MS);
		mlx->plane_y = old_plan_x * sin(-ROT_MS) + mlx->plane_y * cos(-ROT_MS);
	}
}

void	move_player_sides(int keycode, t_mlx *mlx)
{
	if (keycode == A)
	{
		if (g_c_map[(int)(mlx->pos_x - mlx->dir_y * MS)][(int)mlx->pos_y] == 0)
			mlx->pos_x -= mlx->dir_y * MS;
		if (g_c_map[(int)mlx->pos_x][(int)(mlx->pos_y + mlx->dir_x * MS)] == 0)
			mlx->pos_y += mlx->dir_x * MS;
	}
	if (keycode == D)
	{
		if (g_c_map[(int)(mlx->pos_x + mlx->dir_y * MS)][(int)mlx->pos_y] == 0)
			mlx->pos_x += mlx->dir_y * MS;
		if (g_c_map[(int)mlx->pos_x][(int)(mlx->pos_y - mlx->dir_x * MS)] == 0)
			mlx->pos_y -= mlx->dir_x * MS;
	}
}

void	move_player(int keycode, t_mlx *mlx)
{
	if (keycode == A || keycode == D)
		move_player_sides(keycode, mlx);
	if (keycode == W)
	{
		if (g_c_map[(int)(mlx->pos_x + mlx->dir_x * MS)][(int)mlx->pos_y] == 0)
			mlx->pos_x += mlx->dir_x * MS;
		if (g_c_map[(int)mlx->pos_x][(int)(mlx->pos_y + mlx->dir_y * MS)] == 0)
			mlx->pos_y += mlx->dir_y * MS;
	}
	if (keycode == S)
	{
		if (g_c_map[(int)(mlx->pos_x - mlx->dir_x * MS)][(int)mlx->pos_y] == 0)
			mlx->pos_x -= mlx->dir_x * MS;
		if (g_c_map[(int)mlx->pos_x][(int)(mlx->pos_y - mlx->dir_y * MS)] == 0)
			mlx->pos_y -= mlx->dir_y * MS;
	}
}

int	ft_input(int keycode, t_mlx *mlx)
{
	double	old_dir_x;
	double	old_plan_x;

	if (keycode == ESC)
		exit(1);
	old_dir_x = 0;
	old_plan_x = 0;
	if (keycode == LEFT || keycode == RIGHT)
		move_cam(keycode, mlx, old_dir_x, old_plan_x);
	if (keycode == A || keycode == W || keycode == S || keycode == D)
		move_player(keycode, mlx);
	if (keycode == A || keycode == W || keycode == S || keycode == D
		|| keycode == LEFT || keycode == RIGHT)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
		mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
				&(mlx->line_length), &(mlx->endian));
		raycasting(mlx);
	}
	return (0);
}

	// if (keycode == A || keycode == W || keycode == S || keycode == D
	// 		|| keycode == LEFT || keycode == RIGHT)
	// {
	// 	printf("pos_x[%f] poxY[%f] dir_x[%f] dir_y[%f]",
	// 		mlx->pos_x, mlx->pos_y, mlx->dir_x, mlx->dir_y);
	// 	printf("theta[%f] plan_x[%f] plane_y[%f]\n",
	// 		mlx->teta, mlx->plan_x, mlx->plane_y);
	// }