/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:02:58 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/30 16:31:15 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_verticaly(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
	}
}

#define VALID_BORDER " 1"
#define INVALID_BORDER "Border not closed, char [%c] found.\n"

int	valid_top_row(char **matrix)
{
	int		col;
	int		row;

	col = 0;
	while (matrix[0][col])
	{
		row = 0;
		if (!ft_strchr(VALID_BORDER,  matrix[row][col]))
			return (printf(INVALID_BORDER,  matrix[row][col]), 0);
		while (matrix[row])
		{
			if (matrix[row][col] == ' ')
				row++;
			else if (matrix[row][col] == '1')
				break ;
			else
				return (printf(INVALID_BORDER,  matrix[row][col]), 0);
		}
		col++;
	}
	return (1);
}

int	get_last(char **matrix, int j)
{
	int	i;

	i = 0;
	while (matrix[i] && ft_strlen(matrix[i]) >= j && matrix[i][j])
		i++;
	return (i);
}

int	valid_bottom_row(char **matrix)
{
	int		col;
	int		last;

	col = 0;
	last = get_last(matrix, col) - 1;
	while (matrix[last] && matrix[last][col])
	{
		if (!ft_strchr(VALID_BORDER,  matrix[last][col]))
			return (printf(INVALID_BORDER,  matrix[last][col]), 0);
		while (last >= 0)
		{
			printf("Cheking pos [%d][%d] with char:[%d][%c]\n", col, last, matrix[last][col], matrix[last][col]);
			if (matrix[last][col] == ' ')
				last--;
			else if (matrix[last][col] == '1')
				break ;
			else
				return (printf(INVALID_BORDER,  matrix[last][col]), 0);
		}
		col++;
		last = get_last(matrix, col) - 1;
	}
	return (1);
}

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
					return (1);
				if (matrix[row][col + 1] != '\0' && matrix[row][col + 1] == ' ')
					return (1);
				if (row > 0 && matrix[row - 1][col] == ' ')
					return (1);
				if (matrix[row + 1] != NULL && matrix[row + 1][col] == ' ')
					return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	check_horizontaly(char **map)
{
	(void)map;
}

void	replace_empty_with_wall(char **map)
{
	(void)map;
}

void	parser_map(t_file *file)
{
	ft_print_matrix(file->map, "");
	valid_bottom_row(file->map);
	// valid_top_row(file->map);
	// printf("Is there any space next to a 0? [%d]\n",
	// check_adjacent_spaces(file->map));
	// check_verticaly(file->map);
	// check_horizontaly(file->map);
	// replace_empty_with_wall(file->map);
	// ft_print_matrix(file->map, "");
}
