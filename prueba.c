/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:57:38 by pepe              #+#    #+#             */
/*   Updated: 2023/06/30 17:58:16 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*resize_and_copy(char *ptr, int new_size)
{
	char	*new_ptr;

	new_ptr = malloc((new_size + 1) * sizeof(char));
	strcpy(new_ptr, ptr);
	free(ptr);
	return (new_ptr);
}

void	fill_with_spaces(char **matrix)
{
	int	longest_row;
	int	longest_col;
	int	i;
	int	current_row_length;
	int	j;

	longest_row = 0;
	longest_col = 0;
	i = 0;
	// Find the longest row and column.
	while (matrix[i])
	{
		current_row_length = strlen(matrix[i]);
		if (current_row_length > longest_row)
			longest_row = current_row_length;
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (j > longest_col)
				longest_col = j;
			j++;
		}
		i++;
	}
	// Fill "empty chars" with spaces.
	i = 0;
	while (matrix[i])
	{
		current_row_length = strlen(matrix[i]);
		j = current_row_length;
		while (j < longest_row)
		{
			matrix[i] = resize_and_copy(matrix[i], longest_row);
			matrix[i][j] = ' ';
			matrix[i][j + 1] = '\0';
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int		rows;
	char	**matrix;
	int		i;

	rows = 7;
	matrix = malloc(rows * sizeof(char *));
	matrix[0] = strdup("123");
	matrix[1] = strdup("12");
	matrix[2] = strdup("12345");
	matrix[3] = strdup("1");
	matrix[4] = strdup("      1234     ");
	matrix[5] = strdup("  1      ");
	matrix[6] = NULL;
	fill_with_spaces(matrix);
	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (0);
}
