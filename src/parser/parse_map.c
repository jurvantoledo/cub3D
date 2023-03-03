/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:10:18 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/03 14:01:37 by jvan-tol      ########   odam.nl         */
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
		ft_error("File descriptor failed", EXIT_FAILURE);
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

static int	get_width(char *str, int prev_width, int total_width)
{
	int	width;

	width = 0;
	while (str[width])
	{
		width++;
		if (width > prev_width && total_width < width)
			total_width = width;
	}
	prev_width = width;
	return (total_width);
}

int	parse_width(t_data *data)
{
	int		fd;
	char	*str;
	int		width;
	int		prev_width;
	int		total_width;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("File descriptor failed", EXIT_FAILURE);
	str = get_next_line(fd);
	prev_width = 0;
	total_width = 0;
	while (str)
	{
		total_width = get_width(str, prev_width, total_width);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (total_width);
}

void	remove_lines_until_map(t_data *data)
{
	int		fd;
	char	*str;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("File descriptor failed", EXIT_FAILURE);
	str = get_next_line(fd);
	while (ft_strncmp(str, "1", 1) != 0)
	{
		printf("the lines: %s", str);
		free(str);
		str = get_next_line(fd);
	}
}

void	parse_map(t_data *data)
{
	remove_lines_until_map(data);
	data->map.height = parse_height(data);
	printf("Map height: %d\n", data->map.height);
	data->map.width = parse_width(data);
	printf("Map width: %d\n", data->map.width);
}
