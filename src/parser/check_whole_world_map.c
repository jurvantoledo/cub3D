/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_whole_world_map.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 15:44:50 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/04 17:45:28 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_empty_and_zero(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.world_map[i])
	{
		j = 0;
		while (data->map.world_map[i][j])
		{
			if (data->map.world_map[i][j] == '0')
			{
				if (data->map.world_map[i + 1][j] == ' ' \
					|| data->map.world_map[i - 1][j] == ' ')
				{
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_rest_of_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.world_map[i])
	{
		j = 0;
		while (data->map.world_map[i][j])
		{
			if (!ft_strchr("01", data->map.world_map[i][j]) && \
				((data->map.world_map[i][j] != 'N' || \
				data->map.world_map[i][j] != 'S' || \
				data->map.world_map[i][j] != 'W' || \
				data->map.world_map[i][j] != 'E') || \
				data->map.world_map[i][j] != ' '))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
