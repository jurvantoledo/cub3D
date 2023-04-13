/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_newline_in_map.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 14:05:56 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/13 17:07:12 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*remove_raw_lines_until_map(int fd)
{
	char	*str;
	int		k;

	str = get_next_line(fd);
	k = 0;
	while (str)
	{
		if (ft_strncmp(str, "\n", 1) != 0)
		{
			if (k == 6)
			{
				return (str);
			}
			k++;
		}
		free(str);
		str = get_next_line(fd);
	}
	return (NULL);
}

bool	check_str_lines_for_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '\n')
			return (false);
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n')
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_empty_line_map(t_data *data)
{
	char	*str;
	int		fd;
	int		k;

	fd = open(data->argv[1], O_RDONLY);
	if (!fd)
		return (false);
	str = remove_raw_lines_until_map(fd);
	k = 0;
	while (str && k < data->map.height)
	{
		if (!check_str_lines_for_newline(str))
		{
			free(str);
			return (false);
		}
		k++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (true);
}
