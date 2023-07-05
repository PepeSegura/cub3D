/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:36:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/05 23:39:48 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_args {
	int		argc;
	char	**argv;
}	t_args;

//Map & data map
typedef struct s_file {
	char	**file;
	char	**map;
	char	**textures;
	int		t_count;
	int		m_count;
}	t_file;

typedef struct s_textures {
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*ceiling_txt;
	int		ceiling_mlx;
	char	*floor_txt;
	int		floor_mlx;
}	t_textures;

typedef struct s_map {
	char	*dir;
	int		width;
	int		height;
	int		max_alt;
	int		**xyzc;
}	t_map;

typedef struct s_data {
	t_args		args;
	t_file		file;
	t_textures	texture;
	int			fd;
}	t_data;

typedef struct s_player {
	int		x;
	int		y;
	int		facing;
}	t_player;

typedef struct s_image {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_raycasting {
	int		x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
}	t_raycasting;

typedef struct s_mlx {
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				multiplicator;
	int				multi_z;
	int				win_w;
	int				win_h;
	int				size_x;
	int				size_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			teta;
	double			plan_x;
	double			plane_y;
	t_image			tex_north;
	t_image			tex_south;
	t_image			tex_east;
	t_image			tex_west;
	int				x;
	int				y;
	t_player		player;
	t_map			map;
	t_data			data;
}	t_mlx;

typedef struct s_vtex {
	int		i;
	double	wallx;
	int		tex[3];
	int		line_h;
	double	pos[2];
}	t_vtex;

#endif
