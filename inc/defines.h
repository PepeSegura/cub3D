/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:11:20 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/06 21:46:39 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*__Constants__*/
# define TRUE 			1
# define FALSE 			0

/*__Game_Settings__*/
# define MS				1
# define ROT_MS			0.2

// # define MAP_WIDTH		24
// # define MAP_HEIGHT		24
# define SCREEN_WIDTH	1280
# define SCREEN_HEIGHT	720

# define MINIMAP_SIZE	200
# define CELL_SIZE	5

/*__Map_Chars__*/
# define VALID_CHARS		" 01NSEW"
# define EMPTY_CHAR			'0'
# define WALL_CHAR			'1'
# define NORTH_CHAR			'N'
# define SOUTH_CHAR			'S'
# define EAST_CHAR			'E'
# define WEST_CHAR			'W'

/*__Keys_&_Events__*/
#ifdef OSX
#
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

#else
# ifndef LINUX
# define LINUX
# endif
# define ESC		65307
# define W		119
# define A		97
# define S		115
# define D		100

# define UP		65362
# define LEFT		65361
# define DOWN		65364
# define RIGHT		65363


/*__Errors__*/
# include "errors.h"

#endif
#endif
