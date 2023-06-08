/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:38:21 by davgarci          #+#    #+#             */
/*   Updated: 2023/03/25 00:41:35 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_raycasting(t_mlx *mlx, t_raycasting *r)
{
	r->hit = 0;
	r->camera_x = 2 * r->x / (double)SCREEN_WIDTH - 1;
	r->ray_dir_x = mlx->dir_x + mlx->plan_x * r->camera_x;
	r->ray_dir_y = mlx->dir_y + mlx->plane_y * r->camera_x;
	r->delta_dist_x = sqrt(1 + (r->ray_dir_y * r->ray_dir_y)
			/ (r->ray_dir_x * r->ray_dir_x));
	r->delta_dist_y = sqrt(1 + (r->ray_dir_x * r->ray_dir_x)
			/ (r->ray_dir_y * r->ray_dir_y));
	r->map_x = (int)mlx->pos_x;
	r->map_y = (int)mlx->pos_y;
}

void	check_walls(t_raycasting *r, t_mlx *mlx)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (mlx->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - mlx->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (mlx->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - mlx->pos_y) * r->delta_dist_y;
	}
}

void	trow_rays(t_raycasting *r)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (g_c_map[r->map_x][r->map_y] > 0)
			r->hit = 1;
	}
}

void	raycasting(t_mlx *mlx)
{
	t_raycasting	r;

	ft_memset(&r, 0, sizeof(t_raycasting));
	while (r.x < SCREEN_WIDTH)
	{
		ft_init_raycasting(mlx, &r);
		check_walls(&r, mlx);
		trow_rays(&r);
		if (r.side == 0)
			r.perp_wall_dist = (r.map_x - mlx->pos_x + (1 - r.step_x) / 2)
				/ r.ray_dir_x;
		else
			r.perp_wall_dist = (r.map_y - mlx->pos_y + (1 - r.step_y) / 2)
				/ r.ray_dir_y;
		r.line_height = (int)(SCREEN_HEIGHT / r.perp_wall_dist);
		r.draw_start = -r.line_height / 2 + SCREEN_HEIGHT / 2;
		if (r.draw_start < 0)
			r.draw_start = 0;
		r.draw_end = r.line_height / 2 + SCREEN_HEIGHT / 2;
		if (r.draw_end >= SCREEN_HEIGHT)
			r.draw_end = SCREEN_HEIGHT - 1;
		vertical_texture(&r, mlx, r.perp_wall_dist);
		r.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
