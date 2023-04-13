/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 14:13:30 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/13 16:23:55 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	**create_map(char *mapline)
{
	char	**map;
	char	*temptrim;

	temptrim = ft_strtrim(mapline, "\n");
	free(mapline);
	if (!temptrim)
		return (NULL);
	map = ft_split(temptrim, '\n');
	if (!map)
	{
		free(temptrim);
		return (NULL);
	}
	free(temptrim);
	return (map);
}

char	*get_map_utils(int fd)
{
	char	*line;
	char	*str;

	line = NULL;
	str = get_next_line(fd);
	while (str)
	{
		if (ft_strncmp(str, "\n", 1) != 0)
		{
			line = ft_strdup(str);
			free(str);
			return (line);
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (line);
}

char	**get_raw_map(t_data *data)
{
	int		fd;
	char	*str;
	char	*line;
	char	*newline;

	fd = open(data->argv[1], O_RDONLY);
	if (!fd)
		return (NULL);
	line = get_map_utils(fd);
	if (line == NULL)
		return (NULL);
	while (line)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		newline = line;
		line = ft_strjoin(newline, str);
		free(newline);
		free(str);
	}
	free(str);
	close(fd);
	return (create_map(line));
}

char	**get_world_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
		i++;
	return (&data->map.raw_map[i]);
}

bool	parse_map(t_data *data)
{
	data->map.raw_map = get_raw_map(data);
	if (!data->map.raw_map)
		return (false);
	data->map.texture[0] = get_textures(data, "NO");
	data->map.texture[1] = get_textures(data, "SO");
	data->map.texture[2] = get_textures(data, "WE");
	data->map.texture[3] = get_textures(data, "EA");
	data->map.floor = get_floor_ceiling(data, "F");
	data->map.ceiling = get_floor_ceiling(data, "C");
	if (!map_checks(data))
		return (false);
	data->map.height = parse_height_new(data);
	data->map.width = parse_width_new(data);
	data->map.world_map = get_world_map(data);
	if (!data->map.world_map)
		return (false);
	if (check_empty_line_map(data) == false)
		return (false);
	return (true);
}
