/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures_and_map_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:58:20 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/15 17:45:54 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_texture(char *line)
{
	int			i;
	const char	*textures[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};

	if (!line)
		return (0);
	i = -1;
	while (textures[++i])
		if (ft_strnstr(line, textures[i], ft_strlen(textures[i])) != NULL)
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
			ft_print_error(INVALID_CHAR);
		i++;
	}
	return (1);
}

int	check_isles(t_file *file, int i)
{
	int	flag;

	flag = 0;
	while (file->file[i])
	{
		if (ft_str_is_space(file->file[i]))
		{
			flag = 1;
			i++;
			continue ;
		}
		if (check_line(file->file[i]) == 1)
			ft_print_error(ISLANDS);
	}
	return (flag);
}
