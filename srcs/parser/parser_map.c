/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:02:58 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/01 16:10:18 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define VALID_BORDER " 1"
#define INVALID_BORDER "Border not closed."

int	valid_top_row(char **matrix)
{
	int	col;
	int	row;

	col = 0;
	while (matrix[0][col])
	{
		row = 0;
		if (!ft_strchr(VALID_BORDER, matrix[row][col]))
			ft_print_error(INVALID_BORDER);
		while (matrix[row])
		{
			if (matrix[row][col] == ' ')
				row++;
			else if (matrix[row][col] == '1')
				break ;
			else
				ft_print_error(INVALID_BORDER);
		}
		col++;
	}
	return (0);
}

int	valid_bottom_row(char **matrix)
{
	int	col;
	int	last;
	int	len;

	col = 0;
	len = ft_len_matrix(matrix);
	last = len - 1;
	while (matrix[last] && matrix[last][col])
	{
		last = len - 1;
		if (!ft_strchr(VALID_BORDER, matrix[last][col]))
			ft_print_error(INVALID_BORDER);
		while (last >= 0)
		{
			if (matrix[last][col] == ' ')
				last--;
			else if (matrix[last][col] == '1')
				break ;
			else
				ft_print_error(INVALID_BORDER);
		}
		col++;
	}
	return (0);
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

int	check_left_column(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(VALID_BORDER, str[i]))
			ft_print_error(INVALID_BORDER);
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '1')
			return (0);
		else
			ft_print_error(INVALID_BORDER);
		i++;
	}
	return (0);
}

int	check_right_column(char *str)
{
	int	i;
	int	border;

	i = 0;
	border = ft_strlen(str) - 1;
	while (border >= 0)
	{
		if (!ft_strchr(VALID_BORDER, str[border]))
			ft_print_error(INVALID_BORDER);
		while (border >= 0 && str[border] == ' ')
			border--;
		if (str[border] == '1')
			return (0);
		else
			ft_print_error(INVALID_BORDER);
		i++;
	}
	return (0);
}

void	check_sides(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		check_left_column(map[i]);
		check_right_column(map[i]);
	}
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

void	check_borders_and_voids(t_file *file)
{
	check_adjacent_spaces(file->map);
	valid_top_row(file->map);
	valid_top_row(file->map);
	check_sides(file->map);
}

void	parser_map(t_file *file)
{
	fill_with_spaces(file->map);
	ft_print_matrix(file->map, "map");
	check_borders_and_voids(file);
	replace_space_to_wall(file->map);
	ft_print_matrix(file->map, "FILLED");
}
