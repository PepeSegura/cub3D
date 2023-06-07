/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:15:35 by psegura-          #+#    #+#             */
/*   Updated: 2023/03/25 01:02:27 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_file_size(t_cosas *c)
{
	char	*line;

	c->fd = open(c->args.argv[1], O_RDONLY);
	if (c->fd == -1)
		ft_perror("");
	line = "";
	while (line)
	{
		line = get_next_line(c->fd);
		if (line)
		{
			c->file.file_size++;
			free(line);
		}
		else
			break ;
	}
	close(c->fd);
}

void	ft_store_file(t_cosas *c)
{
	int		i;
	char	*aux;

	i = 0;
	ft_file_size(c);
	c->fd = open(c->args.argv[1], O_RDONLY);
	if (c->fd == -1)
		ft_perror("");
	c->file.file = (char **)malloc((c->file.file_size + 2) * sizeof(char *));
	c->file.file[c->file.file_size] = NULL;
	while (i < c->file.file_size)
	{
		aux = get_next_line(c->fd);
		c->file.file[i] = ft_strtrim(aux, "\n");
		if (!c->file.file[i])
			ft_free_matrix(c->file.file);
		free(aux);
		i++;
	}
}
