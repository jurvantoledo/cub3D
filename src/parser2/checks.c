/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 15:50:31 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/22 16:53:44 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	check_for_data(t_data *data)
{
	if ((data->map.texture[0] == NULL || data->map.texture[1] == NULL) \
		|| data->map.texture[2] == NULL || data->map.texture[3] == NULL \
		|| data->map.floor == 0 || data->map.ceiling == 0)
	{
		return (false);
	}
	return (true);
}

int	check_key_data(t_data *data)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < 6)
	{
		if (ft_strncmp(data->map.raw_map[index], "NO", 2) == 0)
			count++;
		if (ft_strncmp(data->map.raw_map[index], "SO", 2) == 0)
			count++;
		if (ft_strncmp(data->map.raw_map[index], "WE", 2) == 0)
			count++;
		if (ft_strncmp(data->map.raw_map[index], "EA", 2) == 0)
			count++;
		if (ft_strncmp(data->map.raw_map[index], "F", 1) == 0)
			count++;
		if (ft_strncmp(data->map.raw_map[index], "C", 1) == 0)
			count++;
		index++;
	}
	if (count != 6)
		return (0);
	return (count);
}

bool	map_checks(t_data *data)
{
	if (!check_for_data(data))
		return (false);
	if (check_key_data(data) == 0)
		return (false);
	return (true);
}
