/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_textures.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 15:20:07 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/08 14:15:28 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	get_textures(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], "NO", 2) == 0)
		{
			data->map.texture[0] = str;
		}
		if (ft_strncmp(&str[i], "SO", 2) == 0)
		{
			data->map.texture[1] = str;
		}
		if (ft_strncmp(&str[i], "WE", 2) == 0)
		{
			data->map.texture[2] = str;
		}
		if (ft_strncmp(&str[i], "EA", 2) == 0)
		{
			data->map.texture[3] = str;
		}
		i++;
	}
}

void	parse_textures(t_data *data)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(data->argv[1], O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		get_textures(data, ft_strdup(str));
		free(str);
		str = get_next_line(fd);
	}
	printf("the NO texture: %s\n", data->map.texture[0]);
	printf("the SO texture: %s\n", data->map.texture[1]);
	printf("the WE texture: %s\n", data->map.texture[2]);
	printf("the EA texture: %s\n", data->map.texture[3]);
	close(fd);
}
