/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/06 14:27:12 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_map {
	int		fd;
	int		height;
	int		width;
	char	**map;
	char	*texture[4];
	char	*ceiling;
	char	*floor;
}	t_map;

typedef struct s_data {
	int		argc;
	char	**argv;

	t_map	map;
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