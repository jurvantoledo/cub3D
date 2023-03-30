/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_world_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 15:50:38 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/30 12:26:21 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	check_left_wall(t_data *data, int k)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(data->map.world_map[k]))
	{
		if (data->map.world_map[k][i] != '1')
		{
			if (data->map.world_map[k][i] == '0')
				return (false);
		}
		else
			break ;
		i++;
	}
	return (true);
}

static bool	check_right_wall(t_data *data, int i)
{
	size_t	k;

	k = ft_strlen(data->map.world_map[i]);
	while (1)
	{
		if (data->map.world_map[i][k] != '1')
		{
			if (data->map.world_map[i][k] == '0')
				return (false);
		}
		else
			break ;
		k--;
	}
	return (true);
}

static bool	check_side_walls(t_data *data)
{
	int		i;

	i = 1;

	while (i < data->map.height)
	{
		if (!check_left_wall(data, i))
			return (false);
		if (!check_right_wall(data, i))
			return (false);
		i++;
	}
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
	return (true);
}
