/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:16:16 by hakahmed          #+#    #+#             */
/*   Updated: 2023/07/10 14:01:32 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Starting from scratch...

#include <math.h>

#include "cub3d.h"
#include "defines.h"
#include "mlx.h"
#include "structures.h"

static void	initialize(t_mlx *mlx, t_raycasting* r)
{
	r->camera_x = 2 * mlx->x / (double)SCREEN_WIDTH - 1;
	r->ray_dir_x = mlx->dir_x + mlx->plan_x * r->camera_x;
	r->ray_dir_y = mlx->dir_y + mlx->plane_y * r->camera_x;
	r->delta_dist_x = sqrt(1 + pow(r->ray_dir_y, 2) / pow(r->ray_dir_x, 2));
	r->delta_dist_y = sqrt(1 + pow(r->ray_dir_x, 2) / pow(r->ray_dir_y, 2));
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

}

static void 	cast_rays(t_mlx *mlx, t_raycasting* r)
{

}

void	raycasting(t_mlx *mlx)
{
	t_raycasting	*r;
	int		i;

	r = ft_calloc(sizeof(t_raycasting), 1);
	if (!r)
		return;
	i = -1;
	while (++i < SCREEN_WIDTH)
		cast_rays(mlx, r);
	free(r);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
