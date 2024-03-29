/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:31:36 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/17 18:07:04 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_color(t_mlx *data, int texx, int texy, char *addr)
{
	if (texx >= 0 && texx < data->x && texy >= 0 && texy < data->y)
		return (*(int *)(addr + (4 * data->x * texy) + (4 * texx)));
	return (0);
}

void	vertical_texture(t_raycasting *r, t_mlx	*mlx)
{
	t_vtex	v;

	ft_memset(&v, 0, sizeof(t_vtex));
	v.tex[2] = r->x;
	v.line_h = r->draw_end - r->draw_start;
	if (r->side == 0)
		v.wallx = mlx->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		v.wallx = mlx->pos_x + r->perp_wall_dist * r->ray_dir_x;
	v.wallx -= floor(v.wallx);
	v.tex[0] = (int)(v.wallx * (double)mlx->x);
	if (r->side == 0 && r->ray_dir_x > 0)
		v.tex[0] = 64 - v.tex[0] - 1;
	else if (r->side == 1 && r->ray_dir_y < 0)
		v.tex[0] = 64 - v.tex[0] - 1;
	v.pos[1] = ((double)mlx->y / r->line_height);
	v.pos[0] = (v.wallx) + ((r->line_height - v.line_h) / (double)2) * v.pos[1];
	draw_textures(r, mlx, &v);
}

void	aux_mlx_pixel_put(t_raycasting *r, t_mlx *mlx, t_vtex *v, void *ptr)
{
	v->tex[1] = (int)v->pos[0];
	v->pos[0] += v->pos[1];
	my_mlx_pixel_put(mlx, r->x, v->i,
		get_tex_color(mlx, v->tex[0], v->tex[1], ptr));
}

void	draw_textures(t_raycasting *r, t_mlx *mlx, t_vtex *v)
{
	v->i = -1;
	while (++v->i < r->draw_start)
		my_mlx_pixel_put(mlx, r->x, v->i, mlx->data.texture.ceiling_mlx);
	while (++v->i < r->draw_end)
	{
		if (r->side == 0)
		{
			if (r->ray_dir_x < 0)
				aux_mlx_pixel_put(r, mlx, v, mlx->tex[NORTH].addr);
			else
				aux_mlx_pixel_put(r, mlx, v, mlx->tex[SOUTH].addr);
		}
		else
		{
			if (r->ray_dir_y < 0)
				aux_mlx_pixel_put(r, mlx, v, mlx->tex[WEST].addr);
			else
				aux_mlx_pixel_put(r, mlx, v, mlx->tex[EAST].addr);
		}
	}
	while (++v->i < SCREEN_HEIGHT)
		my_mlx_pixel_put(mlx, r->x, v->i, mlx->data.texture.floor_mlx);
}

void	draw_sky_floor(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(mlx, x, y, mlx->data.texture.ceiling_mlx);
			else
				my_mlx_pixel_put(mlx, x, y, mlx->data.texture.floor_mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
