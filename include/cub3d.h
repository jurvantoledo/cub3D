/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/07 16:02:17 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map {
	int		height;
	int		width;
	char	**world_map;
	char	*texture[4];
	char	*ceiling;
	char	*floor;
}	t_map;

typedef struct s_data {
	int				argc;
	char			**argv;

	mlx_t			*mlx;
	mlx_texture_t	*textures[4];
	mlx_image_t		*background;
	mlx_image_t		*foreground;
	t_map			map;
	double			move_speed;
	double			rotation_speed;
}	t_data;

/*+++++++++++ Map Parser functions +++++++++++++*/
void	parse_map(t_data *data);
int		parse_height(t_data *data);
int		parse_width(t_data *data);
void	parse_textures(t_data *data);
void	parse_floor_ceiling(t_data *data);
char	*remove_lines_until_map(t_data *data, char *str, int fd);

/*+++++++++++ Error functions +++++++++++++*/
void	ft_error(char *str, int exit_code);

#endif