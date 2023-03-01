/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:10:18 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/01 17:02:54 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_height(t_data *data)
{
	int		fd;
	char	*str;
	int		lines;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", "File descriptor failed");
		return (0);
	}
	str = get_next_line(fd);
	lines = 0;
	while (str)
	{
		lines++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	parse_width(t_data *data)
{
	int		fd;
	char	*str;
	char	**splitted_map;
	int		width;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", "File descriptor failed");
		return (0);
	}
	str = get_next_line(fd);
	splitted_map = ft_split(str, ' ');
	if (!splitted_map)
		return (0);
	width = 0;
	while (splitted_map[width])
	{
		width++;
	}
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	free(splitted_map);
	close(fd);
	return (width);
}

void	parse_map(t_data *data)
{
	data->map.height = parse_height(data);
	printf("Map height: %d\n", data->map.height);
	data->map.width = parse_width(data);
	printf("Map width: %d\n", data->map.width);
}
