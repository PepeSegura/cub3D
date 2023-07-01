/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures_and_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:15:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/01 16:00:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	store_textures(t_file *file)
{
	int	i;

	i = 0;
	while (file->file[i] && file->t_count < 6)
	{
		if (ft_str_is_space(file->file[i]))
		{
			i++;
			continue ;
		}
		if (ft_is_texture(file->file[i]))
		{
			file->textures = ft_add_row_matrix(file->textures, file->file[i]);
			file->t_count++;
			i++;
			continue ;
		}
		if (ft_is_texture(file->file[i]) == 0)
			ft_print_error(INVALID_LINES);
		break ;
	}
	if (file->t_count != 6)
		ft_print_error(MISSING_TEXTURES);
	return (i);
}

int	store_map(t_file *file, int i)
{
	int	flag;

	flag = 0;
	while (file->file[i])
	{
		if (ft_str_is_space(file->file[i]))
		{
			if (flag == 1 && check_isles(file, i) != 1)
			{
				ft_free_matrix(file->map);
				file->map = ft_calloc(1, sizeof(char *));
			}
			i++;
			continue ;
		}
		if (check_line(file->file[i]) == 1)
		{
			file->map = ft_add_row_matrix(file->map, file->file[i]);
			file->m_count++;
			i++;
			flag = 1;
			continue ;
		}
	}
	return (flag);
}

void	store_textures_and_map(t_file *file)
{
	int	i;

	file->map = ft_calloc(1, sizeof(char *));
	file->textures = ft_calloc(1, sizeof(char *));
	if (file->map == NULL || file->textures == NULL)
		ft_print_error("Malloc KO");
	i = store_textures(file);
	if (store_map(file, i) == 0)
		ft_print_error(MISSING_MAP);
}
