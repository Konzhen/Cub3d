/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:38:40 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/19 16:50:58 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

//--------------------------------------------------------------------------//
//	- 							INCLUDES									//
//--------------------------------------------------------------------------//

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42_Int.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

//--------------------------------------------------------------------------//
//	- 							VARIABLES									//
//--------------------------------------------------------------------------//

# define WIDTH 900
# define HEIGHT 720
# define PI 3.1415926535
# define STOCK_ACTION = 0
# define RESET_ACTION = -1
# define RETURN_ACTION = 1

//--------------------------------------------------------------------------//
//	- 							ERRORS										//
//--------------------------------------------------------------------------//

# define ERR_CUB_FILE "can' t open the .cub file"
# define ERR_TEX_FILE "can' t open texture file"
# define ERR_EXTENSION "this extension format is not allowed"
# define ERR_TEX_FORMAT "invalid texture syntax"
# define ERR_COLOR_FORMAT "invalid color syntax"
# define ERR_COLOR_VALUE "invalid color value"
# define ERR_TAB_NOT_VALID "invalid tab"
# define MALLOC "malloc failed"
# define EMPTY_BAIT "did you really try to trap us ?"

//--------------------------------------------------------------------------//
//	-							STRUCTURES									//
//--------------------------------------------------------------------------//
typedef struct s_player
{
	int					hit;
	int					x;
	int					y;
	int					tex_width;
	int					tex_height;
	int					tex_x;
	int					tex_y;
	int					map_x;
	int					map_y;
	char				start;
	int					draw_start;
	int					draw_end;
	double				step;
	double				tex_pos;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	double				wall_x;
	int					step_x;
	int					step_y;
	int					side;
	int					line_height;
}						t_player;

typedef struct s_data
{
	mlx_image_t			*render;
	mlx_texture_t		*texture;
	mlx_texture_t		*texture_n;
	mlx_texture_t		*texture_s;
	mlx_texture_t		*texture_e;
	mlx_texture_t		*texture_w;
	int					r;
	int					g;
	int					b;
	void				*mlx_ptr;
	char				*title;
	struct s_map		*map;
	struct s_player		*player;
}						t_data;

typedef struct s_map
{
	char				**tab;
	int					width;
	int					height;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	t_player			player;
	t_data				map;
}						t_map;

//--------------------------------------------------------------------------//
//	-							FUNCTIONS									//
//--------------------------------------------------------------------------//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./

//	map_fill.c
void					fill_tab(char **blueprint, char ***tab, size_t y);
char					*fill_line(const char *str);

//	main.c
void					draw_player(t_data *mlx);
void					load_image(t_data *data);
void					dir_texture(t_data *data);

//	draw.c
void					pixel_ceiling(t_data *data);
void					pixel_floor(t_data *data);
void					draw_all_elements(t_data *data, t_player *player);

int						render(int params, char **argv);
bool					parser(int argc, char **argv);
int						init(int argc, char **argv);
int						scanlines(int pos_player, int pos_map);
int						error(int i);
int						stocker(int i);

//	movements.c
void					movements(void *param);
//	directions.c
void					rota_right(t_data *data, t_map *map);
void					rota_left(t_data *data, t_map *map);

//	free_structs.c
void					free_map(t_map *map);
void					free_data(t_data *data);
void					free_all(t_data *data);
void					shut_down(void *param);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./utils/

char					*get_next_valid_line(int fd);
char					*get_texture_path(char *line, int *i);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./checker/

//	checker.c
int						checker(char *argv_1);

//	checker_utils.c
bool					check_residue(char *line);
bool					check_color_format(char *line, int *i, bool last);

//	checker_texture.c
bool					check_texture_line(char *line, int dir);

//	checker_tab.c
bool					check_tab(char **tab);

// checker_lines_and_columns.c
bool					check_columns(char **tab);
bool					check_lines(char **tab);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./data/

//	construtors.c
t_map					*map_constructor(void);
t_player				*player_constructor(void);
t_data					*data_constructor(void);

//	get_data.c
t_data					*get_data(int fd, char *argv_1);

//	get_hexa_color.c
uint32_t				get_color_c(int r, int g, int b, int action);
uint32_t				get_color_f(int r, int g, int b, int action);

//	get_player.c
t_player				*get_player(t_data *data, char **tab);

//	get_map.c
bool					set_map(t_map *map, int fd);
t_map					*get_map(int fd, char *argv_1);

//	get_map_utils.c
int						get_color_value(char *line, int *i);
bool					fill_texture(t_map *map, char *line, int dir);
void					get_width_and_height(t_map *map);

//	get_raw_tab.c
char					**get_raw_tab(int fd, char *argv_1);

//	get_tab.c
char					**get_raw_tab(int fd, char *argv_1);
char					**get_tab(char **tab);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./raycasting/
//	raycasting.c
void					shoot_ray(t_data *data);
void					rescale_pixel_size(t_data *data);

// set_colors.c
int						get_rgba(t_data *data);
void					set_rgb(t_data *data);

// calc_ray.c
void					raycasting_loop(t_data *data, t_player *player);
void					raycasting(t_data *data);

// bonus_minimap.c
void					init_minimap(t_data *data);

// init_display_datas.c
void					init_view_side(t_data *data);
void					init_view_distance(t_data *data, t_player *player);
void					init_player_view(t_data *data, t_player *player);
void					init_perp(t_player *player);

#endif
