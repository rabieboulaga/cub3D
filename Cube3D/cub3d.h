/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:57 by rboulaga          #+#    #+#             */
/*   Updated: 2025/05/12 23:01:29 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

#  define HEIGHT 1080
#  define WIDTH 1440
#  define PI 3.14159265358979323846
#  define PLAYER_SPEED 0.02

#  include <math.h>

typedef struct s_img
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*addr;
	int				h;
	int				w;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	double			player_x;
	double			player_y;
	double			player_angle;

	char			facing;
	double			*hit_x;
	double			*hit_y;
	int				ceiling_color;
	int				floor_color;

	char			*wall_directions;
	double			*ray_distances;
	double			*ray_angles;
	char			*key;

}					t_img;

typedef enum e_token
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	MAPP,
	EMPTY,
	NOTHING,
}					t_token;

typedef struct s_coord
{
	int				tex_x;
	int				tex_y;
}					t_coord;

typedef struct c_map
{
	t_token			type;
	char			*line;
	int				flag;
	struct c_map	*next;

}					t_map;

typedef struct c_data
{
	char			**content;
	char			**map1;
	char			*str;
	int				d;
	int				help;
	int				fd;
	int				len;
	char			*file;
	int				flag_no;
	int				flag_so;
	int				flag_we;
	int				flag_ea;
	int				flag_f;
	int				flag_c;
	int				flag_mapp;
	int				flag_empty;
	char			*ea;
	char			*so;
	char			*we;
	char			*no;
	char			*f;
	char			*c;
	int				map_y;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceiling_r;
	int				ceiling_g;
	int				ceiling_b;
	t_img			*wall_textures;
	t_img			*img;
	struct c_map	*map_struct;
}					t_data;

typedef struct s_ray
{
	double			angle;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	int				side;
}					t_ray;

// raycasting functions
void				render(t_data *data);
void				draw(t_data *data, t_img *img);
void				draw_3d_walls(t_data *data);
void				draw_view_ray(t_img *img, char **map);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
int					key_release(int keycode, t_data *data);
int					key_press(int keycode, t_data *data);
int					end(t_data *data);
void				free_all(t_data *data);
void				free_textures(void *mlx, t_img *wall_textures, int count);
int					move_player(t_data *data);
int					get_color(int r, int g, int b);
void				find_player_position(t_data *data);
void				player_facing(t_img *img);
void				wall_hit_point(t_img *img, t_ray *ray,
						int col, double perp_wall_dist);

// parsing functions
void				parsing(int ac, char **av, t_data *data, t_map *map);
char				*get_next_line(int fd);
char				*ft_strjoinn(char *s1, char *s2);
char				*ft_strchrr(char *s, int c);
size_t				ft_strlenn(char *str);
char				*ft_strdupp(char *s);
void				my_exit(t_data *data, char *str);
void				data_extraction(char *file, t_data *data, t_map *map);
// void    check_elements(t_data *data);
t_map				*map_lstlast(t_map *lst);
void				map_add_front(t_map **lst, t_map *new);
void				map_add_back(t_map **lst, t_map *new);
void				check_number_of_elements(t_map *map, t_data *data);
int					my_cmp(char *s1, char *s2, size_t n);
void				check_it(t_map *map, t_data *data);
void				check_arranging(t_data *data, t_map *map);
void				take_map(t_data *data, t_map *map);
void				free_map(t_map *map);
void				check_access(t_data *data, t_map *map);
void				remove_newline(char *str);
void				check_f_rgb(t_data *data, t_map *map);
void				check_c_rgb(t_data *data, t_map *map);
long long			rgb_atoi(const char *str);
void				preparing_elements(t_data *data, t_map *map);
void				free_list(char **str);
void				map_parsing(t_data *data, t_map *map);
void				textures(char *s, t_data *data, t_map *map);
int					is_space(char c);
void				check_hole(t_data *data, t_map *map);
void				take_it(t_data *data, t_map *map);
char				*helper(char *str, t_data *data, t_map *map);
int					rgb_help(char *str);
void				txt_extension(char *av, t_data *data, t_map *map);

# endif
#endif
