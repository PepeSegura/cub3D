/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:16:16 by hakahmed          #+#    #+#             */
/*   Updated: 2023/07/14 01:16:23 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Starting from scratch...

#include <math.h>

#include "cub3d.h"
#include "defines.h"
#include "libft.h"
#include "mlx.h"
#include "structures.h"

static void	initialize(t_mlx *mlx, t_raycasting* r)
{
	r->camera_x = 2 * r->x / (double)SCREEN_WIDTH - 1;
	r->ray_dir_x = mlx->dir_x + mlx->plane_x * r->camera_x;
	r->ray_dir_y = mlx->dir_y + mlx->plane_y * r->camera_x;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
	r->map_x = mlx->pos_x;
	r->map_y = mlx->pos_y;
}

static void	calc_step(t_mlx *mlx, t_raycasting* r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (mlx->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1 - mlx->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (mlx->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1 - mlx->pos_y) * r->delta_dist_y;
	}
}

static void	digital_differential_analyzer(t_mlx *mlx, t_raycasting* r)
{
	calc_step(mlx, r);
	while (TRUE)
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
		if (mlx->map.xyzc[r->map_x][r->map_y] > 0)
			break;
	}
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
}

static void 	cast_rays(t_mlx *mlx, t_raycasting* r)
{
	initialize(mlx, r);
	digital_differential_analyzer(mlx, r);
	r->line_height = SCREEN_HEIGHT / r->perp_wall_dist;
	r->draw_start = -r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_end >= SCREEN_HEIGHT)
		r->draw_end = SCREEN_HEIGHT - 1;
	vertical_texture(r, mlx);
}

void	raycasting(t_mlx *mlx)
{
	t_raycasting	r;

	ft_bzero(&r, sizeof(r));
	r.x = -1;
	while (++(r.x) < SCREEN_WIDTH)
		cast_rays(mlx, &r);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
