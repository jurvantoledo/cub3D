/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:10:18 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/06 14:54:25 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	data->map.map = ft_calloc(sizeof(char *), data->map.height);
	i = 0;
	while (i < data->map.height)
	{
		data->map.map[i] = ft_calloc(sizeof(char), data->map.width);
		split_map = ft_split(str, '\n');
		j = 0;
		while (j < data->map.width)
		{
			data->map.map[i][j] = split_map[i][j];
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	// int	test1 = 0;
	// int	test2;
	// while (data->map.map[test1])
	// {
	// 	test2 = 0;
	// 	while (data->map.map[test1][test2])
	// 	{
	// 		printf("%c\n", data->map.map[test1][test2]);
	// 		test2++;
	// 	}
	// 	test1++;
	// }
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
