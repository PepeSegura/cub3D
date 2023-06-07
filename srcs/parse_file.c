/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:15:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/03/25 01:03:07 by psegura-         ###   ########.fr       */
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

void	ft_count_things(t_cosas *c)
{
	int	i;

	i = 0;
	while (c->file.file[i] && c->file.t_count < 6)
	{
		if (ft_is_texture(c->file.file[i]))
			c->file.t_count++;
		i++;
	}
	if (c->file.t_count != 6)
		ft_print_error("Missing textures in the file.");
	while (c->file.file[i] && ft_str_is_space(c->file.file[i]))
		i++;
	while (c->file.file[i] && c->file.file[i][0] != '\0')
	{
		c->file.m_count++;
		i++;
	}
	if (c->file.m_count == 0)
		ft_print_error("The map is not at the end.");
}

void	ft_copy_textures(t_cosas *c, int *i, int *j)
{
	c->file.t_count = 0;
	while (c->file.file[++(*i)] && c->file.t_count < 6)
	{
		if (ft_is_texture(c->file.file[(*i)]))
		{
			c->file.textures[(*j)++] = ft_strdup(c->file.file[(*i)]);
			c->file.t_count++;
		}
	}
}

void	ft_copy_map(t_cosas *c, int *i, int *j)
{
	while (c->file.file[(*i)] && c->file.file[(*i)][0] != '\0')
	{
		c->file.map[(*j)++] = ft_strdup(c->file.file[(*i)]);
		(*i)++;
	}
}

void	ft_store_things(t_cosas *c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	c->file.map = (char **)ft_calloc((c->file.m_count + 1), sizeof(char *));
	c->file.textures = (char **)ft_calloc((c->file.t_count + 1), sizeof(char *));
	if (c->file.map == NULL || c->file.textures == NULL)
		ft_print_error("Malloc KO");
	ft_copy_textures(c, &i, &j);
	j = 0;
	while (c->file.file[i] && ft_str_is_space(c->file.file[i]))
		i++;
	ft_copy_map(c, &i, &j);
}
