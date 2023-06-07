/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:40:34 by psegura-          #+#    #+#             */
/*   Updated: 2023/03/25 01:54:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*int_to_hex(int num)
{
	char		*hex;
	const char	hexchar[] = "0123456789abcdef";

	if (num > 0xff)
		ft_print_error("Color: Number out of range!");
	hex = ft_calloc(4, sizeof(char));
	if (!hex)
		return (NULL);
	hex[0] = hexchar[(num >> 4) & 0xf];
	hex[1] = hexchar[num & 0xf];
	hex[2] = '\0';
	return (hex);
}

char	*int_to_color(int a, int b, int c)
{
	char	*final;
	char	*aux;

	final = (char *)ft_calloc(9, sizeof(char));
	if (!final)
		ft_print_error("Malloc KO!");
	final[0] = '0';
	final[1] = 'x';
	aux = int_to_hex(a);
	ft_strlcat(final, aux, 5);
	free(aux);
	aux = int_to_hex(b);
	ft_strlcat(final, aux, 7);
	free(aux);
	aux = int_to_hex(c);
	ft_strlcat(final, aux, 9);
	free(aux);
	return (final);
}

char	**check_color_errors(char *str, char **matrix)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			ft_print_error("Color: Invalid char in the colors!");
		i++;
	}
	if (!ft_isdigit(str[i - 1]) || !ft_isdigit(str[0]))
		ft_print_error("Color: The colors must start/finish with a number!");
	matrix = ft_split(str, ',');
	if (matrix == NULL || ft_len_matrix(matrix) != 3)
		ft_print_error("Color: You can only have 3 colors!");
	i = 0;
	while (matrix[i])
	{
		if (ft_strlen(matrix[i]) > 3)
			ft_print_error("Color: Number out of range!");
		i++;
	}
	return (matrix);
}

char	*convert_color_to_hex(char *str)
{
	char	**matrix;
	char	*final;
	int		r;
	int		g;
	int		b;

	if (!str)
		ft_print_error("Color: There is no colors!");
	matrix = NULL;
	matrix = check_color_errors(str, matrix);
	r = ft_atoi(matrix[0]);
	g = ft_atoi(matrix[1]);
	b = ft_atoi(matrix[2]);
	final = int_to_color(r, g, b);
	ft_free_matrix(matrix);
	return (final);
}
