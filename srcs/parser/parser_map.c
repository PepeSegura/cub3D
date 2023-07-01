/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:02:58 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/01 20:11:02 by psegura-         ###   ########.fr       */
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

void	str_replace(char *str, char in, char out)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == in)
			str[i] = out;
}

void	replace_space_to_wall(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		str_replace(map[i++], ' ', '1');
}

// void	check_borders_and_voids(t_file *file)
void	check_borders_and_voids(char **map)
{
	
	check_adjacent_spaces(map);
	valid_top_row(map);
	valid_top_row(map);
	check_sides(map);
}

// void	parser_map(t_file *file)
void	parser_map(t_mlx *mlx)
{
	char **map = NULL;

	map = mlx->data.file.map;
	fill_with_spaces(map);
	// ft_print_matrix(map, "map");
	check_borders_and_voids(map);
	replace_space_to_wall(map);
	ft_print_matrix(map, "FILLED");
	//TODO: LOCATE AND SET PLAYER, PROBABLY IS BETTER TO DO IT ON INIT_MLX.
	// locate_player(map);
}
