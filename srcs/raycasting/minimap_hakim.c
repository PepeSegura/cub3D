/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_hakim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:38:02 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/17 16:47:10 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
