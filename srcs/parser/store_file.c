/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 02:15:35 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/03 22:27:26 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_extension(char *file)
{
	int		len;
	int		ext_pos;

	len = ft_strlen(file);
	ext_pos = len - 4;
	if (ft_strcmp(file, ".cub") == 0 || ft_strcmp(file + ext_pos, ".cub") != 0)
		ft_print_error(NOT_CUB);
}

void	store_file_join(t_data *c)
{
	int		fd;
	char	*line;
	char	*clean;

	line = "line";
	clean = "clean";
	check_extension(c->args.argv[1]);
	c->file.file = ft_calloc(sizeof(char *), 1);
	fd = open(c->args.argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror(c->args.argv[1]);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean = ft_strtrim(line, "\n");
		free(line);
		c->file.file = ft_add_row_matrix(c->file.file, clean);
	}
	close(fd);
}
