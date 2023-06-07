/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:11:20 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/07 18:24:43 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//Constantes
# define TRUE 			1
# define FALSE 			0
# define MS				1
# define ROT_MS			0.2

//Map char
# define VALID_CHARS		"01NSEW "
# define EMPTY_CHAR			'0'
# define WALL_CHAR			'1'
# define NORTH_CHAR			'E'
# define SOUTH_CHAR			'S'
# define EAST_CHAR			'E'
# define WEST_CHAR			'W'

//Keys && Events
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# define UP			126
# define LEFT		123
# define DOWN		125
# define RIGHT		124
# define DESTROY 	17

#endif
