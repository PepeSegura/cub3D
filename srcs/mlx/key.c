/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:56:48 by hakahmed          #+#    #+#             */
/*   Updated: 2023/07/14 18:42:54 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	move_cam(int keycode, t_mlx *mlx)
{
	double	rot_ms;
	double	old_dir_x;
	double	old_plane_x;

	rot_ms = ROT_MS;
	if (keycode == RIGHT)
		rot_ms = -rot_ms;
	old_dir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(rot_ms) - mlx->dir_y * sin(rot_ms);
	mlx->dir_y = old_dir_x * sin(rot_ms) + mlx->dir_y * cos(rot_ms);
	old_plane_x = mlx->plane_x;
	mlx->plane_x = mlx->plane_x * cos(rot_ms) - mlx->plane_y * sin(rot_ms);
	mlx->plane_y = old_plane_x * sin(rot_ms) + mlx->plane_y * cos(rot_ms);
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

	if (keycode == ESC)
		exit(1);
	if (!keycode_is_in(inputs, 6, keycode))
		return (0);
	if (keycode_is_in(camera, 2, keycode))
		move_cam(keycode, mlx);
	if (keycode_is_in(movement, 4, keycode))
		move_player(keycode, mlx);
	if (keycode_is_in(inputs, 6, keycode))
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		raycasting(mlx);
	}
	return (0);
}
