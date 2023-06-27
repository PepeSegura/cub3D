/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:02:58 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/27 21:46:17 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_verticaly(char **map)
{
	(void)map;
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
	check_verticaly(file->map);
	check_horizontaly(file->map);
	replace_empty_with_wall(file->map);
	ft_print_matrix(file->map, "");
}
