/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:41:06 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/17 16:45:15 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define BORDER 2

typedef struct s_mini
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mini;

void	my_mlx_pixel_put2(t_mini *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_background(t_mlx *mlx, int map_height, int map_widht)
{
	int	i;
	int	j;

	i = BORDER;
	j = BORDER;
	while (i < map_height - BORDER)
	{
		while (j < map_widht - BORDER)
		{
			my_mlx_pixel_put(mlx, i, j, 0xffffff);
			j++;
		}
		i++;
		j = BORDER;
	}
}

int	choose_color(int **map, int i, int j)
{
	if (map[i][j] == 0)
		return (0xffffff);
	if (map[i][j] == 1)
		return (0x000000);
	return (0x000000);
}

void	ft_draw_map(t_mlx *mlx, int map_height, int map_widht)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_height - 1)
	{
		while (j < map_widht - 1)
		{
			my_mlx_pixel_put(mlx, i, j,
				choose_color(mlx->map.xyzc, map_height, map_widht));
			j++;
		}
		i++;
		j = 0;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	int	map_widht;
	int	map_height;

	map_widht = SCREEN_WIDTH / 7;
	map_height = map_widht;
	ft_draw_background(mlx, map_widht, map_height);
	ft_draw_map(mlx, mlx->map.height, mlx->map.wide);
}
