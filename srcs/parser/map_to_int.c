/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:18:56 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/17 16:41:07 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_int_matrix(int **map, int rows, int cols)
{
	int	i;
	int	j;

	printf("_____MAP_MATRIX_INT_____\n");
	printf("%s:%d\n", __FILE__, __LINE__);
	i = 0;
	printf("ROWS[%d] COLS [%d]\n", rows, cols);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("________________________\n");
}

void	map_to_int(t_mlx *mlx)
{
	char	**input;
	int		rows;
	int		cols;
	int		i;
	int		j;

	i = 0;
	j = 0;
	input = mlx->data.file.map;
	rows = ft_len_matrix(input);
	cols = ft_strlen(input[0]);
	mlx->map.xyzc = (int **)malloc(rows * sizeof(int *));
	if (!mlx->map.xyzc)
		ft_perror("");
	while (i < rows)
	{
		mlx->map.xyzc[i] = (int *)malloc(cols * sizeof(int));
		j = 0;
		while (j < cols)
		{
			mlx->map.xyzc[i][j] = input[i][j] - '0';
			j++;
		}
		i++;
	}
}
