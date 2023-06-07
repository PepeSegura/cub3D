/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:53:48 by psegura-          #+#    #+#             */
/*   Updated: 2023/03/28 18:58:18 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(0);
}

void	ft_print_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(0);
}

int	hook_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char		*dst;
	static int	quarter_size = sizeof(int) * 8 / 4;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (data->endian == 0)
	{
		*(dst + 0) = color & UCHAR_MAX;
		*(dst + 1) = (color >> quarter_size) & UCHAR_MAX;
		*(dst + 2) = (color >> (quarter_size * 2)) & UCHAR_MAX;
		*(dst + 3) = color >> (quarter_size * 3);
	}
	else
	{
		*(dst + 3) = color & UCHAR_MAX;
		*(dst + 2) = (color >> quarter_size) & UCHAR_MAX;
		*(dst + 1) = (color >> (quarter_size * 2)) & UCHAR_MAX;
		*(dst + 0) = color >> (quarter_size * 3);
	}
}

	//*(unsigned int *)dst = color;