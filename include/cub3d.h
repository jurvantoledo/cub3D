/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/13 16:56:46 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_dpos {
	double	x;
	double	y;
}	t_dpos;

typedef struct s_ipos {
	int	x;
	int	y;
}	t_ipos;

typedef struct s_map {
	t_ipos	dimensions;
	int		height;
	int		width;
	char	**raw_map;
	char	**world_map;
	char	*texture[4];
	int		ceiling;
	int		floor;
}	t_map;

typedef struct s_player {
	t_dpos	loc;
	t_dpos	direction;
	t_dpos	plane;
	t_ipos	mouse;
}	t_player;

typedef struct s_raycast
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	int		side;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	double	wall_x;
	double	wall_y;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_y;
	int		texture_x;
}	t_raycast;

typedef struct s_data {
	int				argc;
	char			**argv;
	mlx_t			*mlx;
	mlx_texture_t	*textures[4];
	mlx_image_t		*background;
	mlx_image_t		*foreground;
	double			move_speed;
	double			rotation_speed;

	t_map			map;
	t_player		player;
	t_dpos			plane;
	t_raycast		ray;
}	t_data;

/*+++++++++++ Map Parser functions +++++++++++++*/
bool	parse_map(t_data *data);
int		parse_height_new(t_data *data);
int		parse_width_new(t_data *data);
int		get_floor_ceiling(t_data *data, char *key);
char	*get_textures(t_data *data, char *key);
bool	map_checks(t_data *data);
int		check_key_data(t_data *data);
bool	check_for_double_komma(char *str, char **arr);
bool	find_textures(t_data *data);
bool	validate_map(t_data *data);
bool	check_world_map(t_data *data);
bool	check_empty_and_zero(t_data *data);
bool	check_floor_ceiling_data(char *str);
bool	check_split_val(char **arr);
bool	check_whole_map(t_data *data);
bool	check_empty_line_map(t_data *data);
bool	count_textures(t_data *data);

/*+++++++++++ Hook functions +++++++++++++*/
void	hook(void *param);
void	move_forward(t_data *data, t_player *player);
void	move_back(t_data *data, t_player *player);
void	move_left(t_data *data, t_player *player);
void	move_right(t_data *data, t_player *player);
void	look_left(t_data *data, t_player *player);
void	look_right(t_data *data, t_player *player);

/*+++++++++++ Raycasting functions +++++++++++++*/
bool	setup(t_data *data);
void	calc_ray_pos_dir(t_raycast *ray, t_player *player, int i);
void	init_ray_len(t_raycast *ray, t_player *player);
void	calc_line_plane(t_raycast *ray, t_player *player);
void	get_vertical_line_height(t_raycast *ray);
void	get_wall_textures(t_raycast *ray, mlx_image_t *image, \
						mlx_texture_t *texture, int w);
void	ft_raycaster(t_data *data, t_player *player);

/*+++++++++++ Error functions +++++++++++++*/
bool	ft_error(char *str, bool ret);

/*+++++++++++ Free functions +++++++++++++*/
int		ft_free(t_data *data, int exit_code);

/*+++++++++++ Util functions +++++++++++++*/
void	free_arr(char **arr);
bool	check_colors(char **arr);
bool	check_location(t_data *data, double x, double y);
char	*ft_remove_spaces_and_key(char *str);

#endif