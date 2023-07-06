/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:22:48 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/06 14:24:26 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	str_replace(char *str, char in, char out)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == in)
			str[i] = out;
}

void	replace_space_to_wall(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		str_replace(map[i++], ' ', '1');
}
