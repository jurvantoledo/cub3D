/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:10:18 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/08 13:48:57 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	print_map(t_data *data)
{
	int	test1;

	test1 = 0;
	while (data->map.world_map[test1])
	{
		printf("map lines: %s\n", data->map.world_map[test1]);
		test1++;
	}
}

void	get_map(t_data *data)
{
	int		fd;
	char	*str;
	int		i;
	int		j;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("File descriptor failed", EXIT_FAILURE);
	str = remove_lines_until_map(data, fd);
	data->map.world_map = ft_calloc(sizeof(char *), data->map.height + 1);
	i = 0;
	while (i < data->map.height)
	{
		data->map.world_map[i] = ft_calloc(sizeof(char), data->map.width + 1);
		j = 0;
		while (j < data->map.width)
		{
			data->map.world_map[i][j] = str[j];
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	print_map(data);
	close(fd);
}

void	parse_map(t_data *data)
{
	parse_textures(data);
	parse_floor_ceiling(data);
	data->map.height = parse_height(data);
	printf("Map height: %d\n", data->map.height);
	data->map.width = parse_width(data);
	printf("Map width: %d\n", data->map.width);
	get_map(data);
}
