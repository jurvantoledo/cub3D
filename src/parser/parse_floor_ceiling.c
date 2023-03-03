/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rest.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 15:21:03 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/03 15:24:24 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
				data->map.floor = ft_strdup(str);
			}
			if (ft_strncmp(&str[i], "C", 1) == 0)
			{
				data->map.ceiling = ft_strdup(str);
			}
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	printf("The floor: %s\n", data->map.floor);
	printf("the ceiling: %s\n", data->map.ceiling);
}
