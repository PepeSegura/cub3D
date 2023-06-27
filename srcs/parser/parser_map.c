/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:02:58 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/28 00:44:02 by pepe             ###   ########.fr       */
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

int	validateTopRow(char **matrix)
{
	int		col;
	char	currentChar;
	int		row;
	int		flag = 0;

	col = 0;
	while (matrix[0][col])
	{
		currentChar = matrix[0][col];
		if (currentChar == '1' || currentChar == ' ')
		{
			row = 0;
			while (matrix[row])
			{
				printf("Checking cord [%d] [%d] with char [%c]\n", row, col, matrix[row][col]);
				if (matrix[row][col] == ' ')
					row++;
				else if (matrix[row][col] == '1')
				{
					flag = 1;
					break ;
				}
			}
		}
		col++;
	}
	// All characters in the top row are either '1' or space
	return (flag);
}

int	checkAdjacentSpaces(char** matrix) {
    int row;
    int col;

	row = 0;
	// Iterate until null pointer is encountered
    while (matrix[row] != NULL) {
        col = 0;
        
        // Iterate until null terminator is encountered
        while (matrix[row][col] != '\0') {
            if (matrix[row][col] == '0') {
                // Check left side
                if (col > 0 && matrix[row][col - 1] == ' ')
                    return 1;

                // Check right side
                if (matrix[row][col + 1] != '\0' && matrix[row][col + 1] == ' ')
                    return 1;

                // Check top
                if (row > 0 && matrix[row - 1][col] == ' ')
                    return 1;

                // Check bottom
                if (matrix[row + 1] != NULL && matrix[row + 1][col] == ' ')
                    return 1;
            }
            col++;
        }
        
        row++;
    }

    // No adjacent spaces found
    return 0;
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
	printf("Is there any space next to a 0? [%d]\n", checkAdjacentSpaces(file->map));
	// check_verticaly(file->map);
	// check_horizontaly(file->map);
	// replace_empty_with_wall(file->map);
	// ft_print_matrix(file->map, "");
}
