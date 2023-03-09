/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/09 13:27:56 by jvan-tol      ########   odam.nl         */
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

typedef struct s_data {
	int				argc;
	char			**argv;
	mlx_t			*mlx;
	mlx_texture_t	*textures[4];
	mlx_image_t		*background;
	mlx_image_t		*foreground;
	t_map			map;
	t_player		player;
	t_dpos			plane;
	double			move_speed;
	double			rotation_speed;
}	t_data;

/*+++++++++++ Map Parser functions +++++++++++++*/
void	parse_map(t_data *data);
int		parse_height(t_data *data);
int		parse_width(t_data *data);
void	parse_textures(t_data *data);
void	parse_floor_ceiling(t_data *data);
char	*remove_lines_until_map(t_data *data, int fd);
bool	find_textures(t_data *data);
bool	validate_map(t_data *data);

/*+++++++++++ Error functions +++++++++++++*/
void	ft_error(char *str, int exit_code);

/*+++++++++++ Hook functions +++++++++++++*/
void	hook(void *param);
void	exec_moves(t_data *data, t_player *player);

/*+++++++++++ Exec functions +++++++++++++*/
bool	setup(t_data *data);

/*+++++++++++ Util functions +++++++++++++*/
void	free_arr(char **arr);

void	test(t_data *cub3d);


#endif