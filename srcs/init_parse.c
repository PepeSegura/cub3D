/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:51:56 by psegura-          #+#    #+#             */
/*   Updated: 2023/03/28 18:55:42 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	aux_set_textures(t_cosas *c, char **aux)
{
	char	*color;
    char	*endptr;

	if (ft_strcmp(aux[0], "C") == 0)
	{
		color = ft_strdup(aux[1]);
		c->texture.ceiling = convert_color_to_hex(color);
		free(color);
		c->texture.cielo = strtol(c->texture.ceiling+2, &endptr, 16);
		printf("CIELO: [%s]\n", c->texture.ceiling);
    	printf("cielo:[%d]\n", c->texture.cielo);
	}
	if (ft_strcmp(aux[0], "F") == 0)
	{
		color = ft_strdup(aux[1]);
		c->texture.floor = convert_color_to_hex(color);
		free(color);
    	c->texture.suelo = strtol(c->texture.floor+2, &endptr, 16);
		printf("SUELO: [%s]\n", c->texture.floor);
    	printf("suelo:[%d]\n", c->texture.suelo);
	}
}

void	set_textures(t_cosas *c)
{
	int		i;
	char	**aux;

	i = 0;
	while (c->file.textures[i])
	{
		aux = ft_split(c->file.textures[i], ' ');
		if (!aux[1])
			ft_print_error("There is no textures in the map!");
		if (ft_strcmp(aux[0], "NO") == 0)
			c->texture.north = ft_strdup(aux[1]);
		if (ft_strcmp(aux[0], "SO") == 0)
			c->texture.south = ft_strdup(aux[1]);
		if (ft_strcmp(aux[0], "WE") == 0)
			c->texture.west = ft_strdup(aux[1]);
		if (ft_strcmp(aux[0], "EA") == 0)
			c->texture.east = ft_strdup(aux[1]);
		if (ft_strcmp(aux[0], "C") == 0 || ft_strcmp(aux[0], "F") == 0)
			aux_set_textures(c, aux);
		i++;
	}
	ft_free_matrix(aux);
}

void	parse_init(t_cosas *c, char **argv)
{
	ft_memset(c, 0, sizeof(t_cosas));
	c->args.argv = argv;
	ft_store_file(c);
	ft_count_things(c);
	ft_store_things(c);
	set_textures(c);
}

