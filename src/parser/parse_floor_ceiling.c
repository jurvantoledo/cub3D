/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_floor_ceiling.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 15:21:03 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/20 16:12:13 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_value(t_data *data, char *str)
{
	char	**split_str;
	char	**split_komma;
	int		val;

	split_str = ft_split(str, ' ');
	if (!split_str)
		return (0);
	split_komma = ft_split(split_str[1], ',');
	if (!split_komma)
		return (0);
	free_arr(split_str);
	val = (ft_atoi(split_komma[0]) << 24) | \
	(ft_atoi(split_komma[1]) << 16) | (ft_atoi(split_komma[2]) << 8) | \
	0x000000FF;
	free_arr(split_komma);
	return (val);
}

void	parse_floor_ceiling(t_data *data)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(data->argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_strncmp(&str[i], "F", 1) == 0)
			{
				data->map.floor = get_value(data, &str[i]);
			}
			if (ft_strncmp(&str[i], "C", 1) == 0)
			{
				data->map.ceiling = get_value(data, &str[i]);
			}
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	printf("The floor: %d\n", data->map.floor);
	printf("the ceiling: %d\n", data->map.ceiling);
}
