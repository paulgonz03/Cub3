/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:52:41 by jonamart          #+#    #+#             */
/*   Updated: 2026/03/19 16:28:50 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MINIMAP_SIZE 12
# define TILE_SIZE 15
# define MINIMAP_OFFSET 20

# define KEYA 97
# define KEYS 115
# define KEYD 100
# define KEYW 119
# define KEYUP 65362
# define KEYRIGHT 65363
# define KEYDOWN 65364
# define KEYLEFT 65361
# define KEYESC 65307
# define CLOSEWIN 17

# define WIDTH 1080
# define HEIGHT 720
# define HALF_H 360
# define PI 3.14159265358979323846

enum			e_tex_id
{
	NO = 0,
	SO,
	WE,
	EA,
	TOTAL
};

typedef struct s_realloc
{
	char		**new_map;
	int			j;
	int			i;
	int			lines;
	int			newline;
}				t_realloc;

typedef struct s_coord_state
{
	int			found[6];
	int			total;
}				t_coord_state;

typedef struct s_files
{
	char		*no_file;
	char		*so_file;
	char		*we_file;
	char		*ea_file;
	char		*f_file;
	char		*c_file;
	int			f_col_r;
	int			f_col_g;
	int			f_col_b;
	int			c_col_r;
	int			c_col_g;
	int			c_col_b;
}				t_files;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct s_minimap
{
	void		*wall_img;
	void		*floor_img;
	void		*player_img;
	void		*void_img;
	int			img_width;
	int			img_height;
}				t_minimap;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*image[4];
	void		*img;
	char		*img_data;
	int			*texture_data[4];
	int			bpp;
	int			bpl;
	int			order_bytes;
	int			img_width;
	int			img_height;
	int			plyr_angle;
	t_minimap	mini_map;
	t_keys		*keys;
	int			tex_width[4];
	int			tex_height[4];
	int			tex_bpp[4];
	int			tex_bpl[4];
	int			tex_endian[4];
}				t_mlx;

typedef struct s_map
{
	char		**map;
	int			lines;
	float		x_plyr;
	float		y_plyr;
	int			x_limit;
	int			y_limit;
	char		view_player;
	char		type;
	t_files		*files;
	t_mlx		*mlx_data;
}				t_map;

typedef struct s_tile_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			end;
}				t_tile_image;

//##################################################
//##                  BONUS                       ##
//##################################################

// Minimap.c
int				mini_map(t_map *map_data, t_minimap *mini_map);
int				load_minimap_textures(t_map *map, t_minimap *mm);
void			*create_tile_img(t_mlx *mlx, int size, int color);
int				get_map_tile(t_map *m, int x, int y);
int				mouse_move(int x, int y, t_mlx *mlx);
int				aux_mouse_move(int delta, int x);

/* ---------------------------------------------------------- */
/*                  STRUCTS  FOR RAYCASTING                   */
/* ---------------------------------------------------------- */

typedef struct s_ray
{
	float		ang;
	float		rad;
	float		dx;
	float		dy;
}				t_ray;

typedef struct s_dda
{
	int			mx;
	int			my;
	int			step_x;
	int			step_y;
	float		delta_x;
	float		delta_y;
	float		side_x;
	float		side_y;
	int			side;
}				t_dda;

typedef struct s_wall
{
	float		dist;
	float		perp;
	float		wall_x;
}				t_wall;

typedef struct s_col
{
	int			h;
	int			start;
	int			end;
	int			real_start;
	int			tex_x;
	int			tex_id;
}				t_col;

typedef struct s_texinfo
{
	int			col;
	int			y;
	float		perp;
	t_col		*c;
}				t_texinfo;

typedef struct s_dcol
{
	int			col;
	int			side;
	t_wall		*w;
	t_ray		*r;
}				t_dcol;

/* RAYCAST CORE */

void			put_pixel(t_mlx *mlx, int x, int y, int color);
void			init_data(t_map *map_data);
int				check_walls(t_mlx *mlx_data, float y, float x, t_map *map_data);
int				game_loop(void *data);
int				raycast(t_map *map_data);
int				closewin(t_mlx *mlx_data);
int				key_press(int keycode, t_mlx *mlx_data);
int				key_release(int keycode, t_mlx *mlx_data);
void			key_moves(t_map *map_data, t_mlx *mlx_data);
void			paint_background(t_map *map_data, t_mlx *mlx_data);
int				init_textures(t_files *files, t_mlx *mlx_data);
void			rays(t_map *map, t_mlx *mlx);
void			draw_column(t_mlx *mlx, t_dcol *d);
void			set_texture_info(t_col *c, t_mlx *mlx, t_dcol *d);
void			init_column(t_col *c, float perp);
void			draw_tex_pixel(t_mlx *mlx, t_texinfo *t);
void			init_ray(t_ray *r, int col, int ang);
void			init_dda(t_dda *d, t_map *map, t_ray *r);
int				select_texture(int side, t_ray *ray);
int				get_tex_x(int w, int side, t_ray *ray, float wx);
int				get_tex_y(int y, int start, int h, int tex_h);
int				apply_shading(int color, float dist);
float			deg_to_rad(float a);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
int				is_wall_block(t_map *map, int y, int x);

/* UTILS / FREE */

void			ft_free_free(char **temp);
int				error(t_map *map_data, char *mes);
void			free_files(t_files *files);
void			free_mlx(t_mlx *mlx);
void			free_mapdata(t_map *map_data);
char			*get_next_line(int fd);

/* MAP / PARSER */

int				line_break(char *line);
int				aux_get_map(char **argv, t_map *data_map);
int				get_map(char **argv, t_map *map_data);
int				process_line_realloc(t_realloc *data, t_map *map_data, int pos);
int				realloc_map(t_map *map_data, int pos);
int				aux_coordinates_parser(t_map *map_data, char *coords[6], int j,
					int i);
int				coordinates_parser(t_map *map_data, char **coords);
char			**copy_map(t_map *map_data);
int				find_player(t_map *map_data);
void			limits_map(t_map *map_data);
int				aux_flood_fill(t_map *map_data, int x, int y, char **map);
int				flood_fill(t_map *map_data);
int				parser(t_map *map_data);
int				char_parser(char **map, char c);
int				char_not_allow(char **map);
int				find_zero(t_map *map_data, char **map);
int				name_map_parser(char **argv);
int				validate_rgb_split(char **rgb);
int				sky_floor(t_map *map_data);
#endif
