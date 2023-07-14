/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:35 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/14 17:21:01 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*__Header_files__*/
# include "libs.h"
# include "defines.h"
# include "structures.h"
# include "errors.h"

/*__Libft__*/
# include "../libft/inc/libft.h"

int		ft_input(int keycode, t_mlx *mlx);
int		hook_exit(t_mlx *mlx);
void	cube_init(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	raycasting(t_mlx *mlx);
void	vertical_texture(t_raycasting *r, t_mlx	*mlx);
void	draw_textures(t_raycasting *r, t_mlx *mlx, t_vtex *v);
void	draw_sky_floor(t_mlx *mlx);

/*__Parse__*/
void	parse_init(t_data *c, char **argv);
void	parser_map(t_mlx *mlx);

/*__Parser_map_aux__*/
void	str_replace(char *str, char in, char out);
void	replace_space_to_wall(char **map);
/*__Check_Borders*/
# define VALID_BORDER " 1"

int		valid_top_row(char **matrix);
int		valid_bottom_row(char **matrix);
void	check_sides(char **map);
int		check_left_column(char *str);
int		check_right_column(char *str);
void	fill_with_spaces(char **matrix);

/*__Convert_map_to_int_array__*/
void	map_to_int(t_mlx *mlx);

/*_Open_&_Store_Map__*/
int		ft_open_file(char *path);
void	ft_store_file(t_data *c);
void	ft_store_textures(t_data *c);
void	ft_store_map(t_data *c);

/*_Utils_*/
void	ft_perror(char *str);
void	ft_print_error(char *str);
int		ft_str_is_space(char *str);

/*_Colors_*/
char	*convert_color_to_hex(char *str);

/*_Input_&_movement_*/
int		ft_exit(void);

/*__Read_Map__*/
void	store_textures_and_map(t_file *file);
int		ft_is_texture(char *line);
int		check_line(char *str);
int		check_isles(t_file *file, int i);

/* Minimap */
void	draw_mm_base(t_mlx *mlx, int h, int w);

#endif
