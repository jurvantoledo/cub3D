/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_world_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 15:50:38 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/28 15:44:39 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	check_left_wall(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map.world_map[i])
	{
		if (data->map.world_map[i][0] != '1')
		{
			if (data->map.world_map[i][0] == '0')
				return (false);
		}
		i++;
	}
	return (true);
}

static bool	check_right_wall(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map.world_map[i])
	{
		if (data->map.world_map[i][data->map.width - 1] != '1')
		{
			if (data->map.world_map[i][data->map.width - 1] == '0')
				return (false);
		}
		i++;
	}
	return (true);
}

static bool	check_side_walls(t_data *data)
{
	if (!check_left_wall(data))
		return (false);
	if (!check_right_wall(data))
		return (false);
	return (true);
}

static bool	check_first_last_line(t_data *data)
{
	int	i;
	int	arr_len;

	arr_len = ft_arraylen(data->map.world_map);
	i = 0;
	while (data->map.world_map[0][i])
	{
		if (data->map.world_map[0][i] != ' ' && \
			data->map.world_map[0][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (data->map.world_map[data->map.height - 1][i])
	{
		if (data->map.world_map[data->map.height - 1][i] != ' ' && \
			data->map.world_map[data->map.height - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_world_map(t_data *data)
{
	if (!check_first_last_line(data))
		return (false);
	if (!check_side_walls(data))
		return (false);
	if (!check_rest_of_map(data))
		return (false);
	return (true);
}
