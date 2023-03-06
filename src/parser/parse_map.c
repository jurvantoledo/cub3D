/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:10:18 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/06 16:04:12 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	print_map(t_data *data)
{
	int	test1;

	test1 = 0;
	while (data->map.map[test1])
	{
		printf("%s", data->map.map[test1]);
		test1++;
	}
}

void	get_map(t_data *data)
{
	int		fd;
	char	*str;
	char	**split_map;
	int		i;
	int		j;

	fd = open(data->argv[1], O_RDONLY);
	str = get_next_line(fd);
	str = remove_lines_until_map(data, str, fd);
	data->map.map = ft_calloc(sizeof(char *), data->map.height + 1);
	i = 0;
	while (i < data->map.height)
	{
		data->map.map[i] = ft_calloc(sizeof(char), data->map.width + 1);
		j = 0;
		while (j < data->map.width)
		{
			data->map.map[i][j] = str[j];
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	print_map(data);
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
