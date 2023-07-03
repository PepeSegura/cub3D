/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:51:56 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/03 20:47:05 by psegura-         ###   ########.fr       */
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
		printf("CEILING: [%s]\n", c->texture.ceiling_txt);
	}
	if (ft_strcmp(aux[0], "F") == 0)
	{
		color = ft_strdup(aux[1]);
		c->texture.floor_txt = convert_color_to_hex(color);
		free(color);
		c->texture.floor_mlx = ft_atol_16(c->texture.floor_txt + 2);
		printf("FLOOR: [%s]\n", c->texture.floor_txt);
	}
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
			c->texture.north = ft_strdup(aux[1]);
		if (ft_strcmp(aux[0], "SO") == 0)
			c->texture.south = ft_strdup(aux[1]);
		if (ft_strcmp(aux[0], "WE") == 0)
			c->texture.west = ft_strdup(aux[1]);
		if (ft_strcmp(aux[0], "EA") == 0)
			c->texture.east = ft_strdup(aux[1]);
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
