/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:30:36 by davgarci          #+#    #+#             */
/*   Updated: 2023/07/06 20:36:36 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fleaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		ft_print_error("Introduce un mapa!");
	ft_memset(&mlx, 0, sizeof(t_mlx));
	parse_init(&mlx.data, argv);
	parser_map(&mlx);
	cube_init(&mlx);
	/* raycasting(&mlx); */
	draw_sky_floor(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, ft_input, &mlx);
	mlx_hook(mlx.win, 17, 0, hook_exit, &mlx);
	mlx_loop(mlx.mlx);
	return (exit(0), 0);
}

	// atexit(&fleaks);
	//mlx_key_hook(mlx.win, ft_input, &mlx);
	//mlx_hook(data->win_ptr, 3, 1L << 1, key_released, data);
