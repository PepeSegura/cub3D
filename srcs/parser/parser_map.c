/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:02:58 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/06 14:24:33 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_adjacent_spaces(char **matrix)
{
	int	row;
	int	col;

	row = 0;
	while (matrix[row] != NULL)
	{
		col = 0;
		while (matrix[row][col] != '\0')
		{
			if (matrix[row][col] == '0')
			{
				if (col > 0 && matrix[row][col - 1] == ' ')
					ft_print_error(INVALID_BORDER);
				if (matrix[row][col + 1] != '\0' && matrix[row][col + 1] == ' ')
					ft_print_error(INVALID_BORDER);
				if (row > 0 && matrix[row - 1][col] == ' ')
					ft_print_error(INVALID_BORDER);
				if (matrix[row + 1] != NULL && matrix[row + 1][col] == ' ')
					ft_print_error(INVALID_BORDER);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	locate_player(t_mlx *mlx)
{
	int		i;
	int		p_count;
	int		j;

	i = 0;
	p_count = 0;
	while (mlx->data.file.map[i])
	{
		j = 0;
		while (mlx->data.file.map[i][j])
		{
			if (ft_strchr("NSEW", mlx->data.file.map[i][j]))
			{
				mlx->player.x = i;
				mlx->player.y = j;
				mlx->player.facing = mlx->data.file.map[i][j];
				p_count++;
				mlx->data.file.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (p_count > 1)
		ft_print_error("Too many players found.");
}

void	check_borders_and_voids(char **map)
{	
	check_adjacent_spaces(map);
	valid_top_row(map);
	valid_top_row(map);
	check_sides(map);
}

void	parser_map(t_mlx *mlx)
{
	char	**map;

	map = mlx->data.file.map;
	fill_with_spaces(map);
	check_borders_and_voids(map);
	replace_space_to_wall(map);
	locate_player(mlx);
	map_to_int(mlx);
}
