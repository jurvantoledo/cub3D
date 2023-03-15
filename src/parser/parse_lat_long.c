/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_lat_long.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 16:02:44 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/15 17:29:38 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*remove_lines_until_map(t_data *data, int fd)
{
	int		k;
	char	*str;

	str = get_next_line(fd);
	k = 0;
	while (str && k < 6)
	{
		if (ft_strncmp(str, "\n", 1) != 0)
		{
			k++;
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	str = get_next_line(fd);
	return (str);
}

int	parse_height(t_data *data)
{
	int		fd;
	char	*str;
	int		lines;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("File descriptor failed", EXIT_FAILURE));
	str = remove_lines_until_map(data, fd);
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
		if (width > prev_width && total_width < width)
		{
			total_width = width;
		}
		width++;
	}
	prev_width = width;
	return (total_width);
}

int	parse_width(t_data *data)
{
	int		fd;
	char	*str;
	int		prev_width;
	int		total_width;

	fd = open(data->argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("File descriptor failed", EXIT_FAILURE));
	str = remove_lines_until_map(data, fd);
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
