/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:51:56 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/14 02:09:12 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_file_join(t_data *c);

void	get_colors(t_data *c, char **aux)
{
	char	*color;

	if (ft_strcmp(aux[0], "C") == 0)
	{
		color = ft_strdup(aux[1]);
		c->texture.ceiling_txt = convert_color_to_hex(color);
		free(color);
		c->texture.ceiling_mlx = ft_atol_16(c->texture.ceiling_txt + 2);
	}
	if (ft_strcmp(aux[0], "F") == 0)
	{
		color = ft_strdup(aux[1]);
		c->texture.floor_txt = convert_color_to_hex(color);
		free(color);
		c->texture.floor_mlx = ft_atol_16(c->texture.floor_txt + 2);
	}
}

static char *free_dup(char *t, const char *s)
{
	free(t);
	return (ft_strdup(s));
}

void	set_textures(t_data *c)
{
	int		i;
	char	**aux;

	i = 0;
	while (c->file.textures[i])
	{
		aux = ft_split(c->file.textures[i], ' ');
		if (!aux[1])
			ft_print_error(MISSING_TEXTURES);
		if (ft_strcmp(aux[0], "NO") == 0)
			c->texture.north = free_dup(c->texture.north, aux[1]);
		if (ft_strcmp(aux[0], "SO") == 0)
			c->texture.south = free_dup(c->texture.south, aux[1]);
		if (ft_strcmp(aux[0], "WE") == 0)
			c->texture.west = free_dup(c->texture.west, aux[1]);
		if (ft_strcmp(aux[0], "EA") == 0)
			c->texture.east = free_dup(c->texture.east, aux[1]);
		if (ft_strcmp(aux[0], "C") == 0 || ft_strcmp(aux[0], "F") == 0)
			get_colors(c, aux);
		ft_free_matrix(aux);
		i++;
	}
}

void	parse_init(t_data *c, char **argv)
{
	ft_memset(c, 0, sizeof(t_data));
	c->args.argv = argv;
	store_file_join(c);
	store_textures_and_map(&c->file);
	set_textures(c);
}
