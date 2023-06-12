/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:15:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/12 05:41:49 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_texture(char *line)
{
	int			i;
	const char	*textures[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	if (!line)
		return (0);
	i = -1;
	while (textures[++i])
		if (ft_strnstr(line, textures[i], ft_strlen(line)) != NULL)
			return (1);
	return (0);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(VALID_CHARS, str[i]))
			ft_print_error("Map error: Invalid char on the map.");
		i++;
	}
	return (1);
}

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
			ft_print_error("Invalid lines before map.");
		break ;
	}
	if (file->t_count != 6)
		ft_print_error("Missing textures in the file.");
	return (i);
}

void	store_map(t_file *file, int i)
{
	file->m_count = 0;
	while (file->file[i])
	{
		if (ft_str_is_space(file->file[i]))
		{
			ft_free_matrix(file->map);
			file->map = ft_calloc(1, sizeof(char *));
			file->m_count = 0;
			i++;
			continue ;
		}
		if (check_line(file->file[i]) == 1)
		{
			file->map = ft_add_row_matrix(file->map, file->file[i]);
			file->m_count++;
			i++;
			continue ;
		}
	}
	if (file->m_count == 0)
		ft_print_error("The map is not at the end.");
}

void	store_textures_and_map(t_file *file)
{
	int	i;

	file->map = ft_calloc(1, sizeof(char *));
	file->textures = ft_calloc(1, sizeof(char *));
	if (file->map == NULL || file->textures == NULL)
		ft_print_error("Malloc KO");
	i = store_textures(file);
	store_map(file, i);
}
