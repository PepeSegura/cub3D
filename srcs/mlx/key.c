/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:39:54 by davgarci          #+#    #+#             */
/*   Updated: 2023/07/06 14:20:27 by psegura-         ###   ########.fr       */
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
	int	temp_x;
	int	temp_y;

	if (keycode == A)
	{
		temp_x = (int)(mlx->pos_x - mlx->dir_y * MS);
		temp_y = (int)(mlx->pos_y + mlx->dir_x * MS);
		if (mlx->map.xyzc[temp_x][(int)mlx->pos_y] == 0)
			mlx->pos_x -= mlx->dir_y * MS;
		if (mlx->map.xyzc[(int)mlx->pos_x][temp_y] == 0)
			mlx->pos_y += mlx->dir_x * MS;
	}
	if (keycode == D)
	{
		temp_x = (int)(mlx->pos_x + mlx->dir_y * MS);
		temp_y = (int)(mlx->pos_y - mlx->dir_x * MS);
		if (mlx->map.xyzc[temp_x][(int)mlx->pos_y] == 0)
			mlx->pos_x += mlx->dir_y * MS;
		if (mlx->map.xyzc[(int)mlx->pos_x][temp_y] == 0)
			mlx->pos_y -= mlx->dir_x * MS;
	}
}

void	move_player(int keycode, t_mlx *mlx)
{
	int	temp_x;
	int	temp_y;

	if (keycode == A || keycode == D)
		move_player_sides(keycode, mlx);
	if (keycode == W)
	{
		temp_x = (int)(mlx->pos_x + mlx->dir_x * MS);
		temp_y = (int)(mlx->pos_y + mlx->dir_y * MS);
		if (mlx->map.xyzc[temp_x][(int)mlx->pos_y] == 0)
			mlx->pos_x += mlx->dir_x * MS;
		if (mlx->map.xyzc[(int)mlx->pos_x][temp_y] == 0)
			mlx->pos_y += mlx->dir_y * MS;
	}
	if (keycode == S)
	{
		temp_x = (int)(mlx->pos_x - mlx->dir_x * MS);
		temp_y = (int)(mlx->pos_y - mlx->dir_y * MS);
		if (mlx->map.xyzc[temp_x][(int)mlx->pos_y] == 0)
			mlx->pos_x -= mlx->dir_x * MS;
		if (mlx->map.xyzc[(int)mlx->pos_x][temp_y] == 0)
			mlx->pos_y -= mlx->dir_y * MS;
	}
}

int	keycode_is_in(const int *arr, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	ft_input(int keycode, t_mlx *mlx)
{
	const int	inputs[6] = {W, A, S, D, LEFT, RIGHT};
	const int	movement[4] = {W, A, S, D};
	const int	camera[2] = {LEFT, RIGHT};
	double		old_dir_x;
	double		old_plan_x;

	if (keycode == ESC)
		exit(1);
	if (!keycode_is_in(inputs, 6, keycode))
		return (0);
	old_dir_x = 0;
	old_plan_x = 0;
	if (keycode_is_in(camera, 2, keycode))
		move_cam(keycode, mlx, old_dir_x, old_plan_x);
	if (keycode_is_in(movement, 4, keycode))
		move_player(keycode, mlx);
	if (keycode_is_in(inputs, 6, keycode))
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
				&(mlx->line_length), &(mlx->endian));
		raycasting(mlx);
	}
	return (0);
}
