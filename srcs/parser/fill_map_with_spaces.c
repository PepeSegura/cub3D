/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_with_spaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:27:06 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/01 18:27:20 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*resize_and_copy(char *ptr, int new_size)
{
	char	*new_ptr;

	new_ptr = malloc((new_size + 1) * sizeof(char));
	ft_strcpy(new_ptr, ptr);
	free(ptr);
	return (new_ptr);
}

void	put_spaces(char **matrix, int longest_row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = ft_strlen(matrix[i]);
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
	while (matrix[i])
	{
		current_row_length = ft_strlen(matrix[i]);
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
	put_spaces(matrix, longest_row);
}
