/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_whole_world_map.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 15:44:50 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/07 14:05:41 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_split_val(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	char_checks(t_data *data, int i, size_t j)
{
	if (j > ft_strlen(data->map.world_map[i + 1] + 1) || \
		j > ft_strlen(data->map.world_map[i - 1] + 1))
		return (false);
	if (data->map.world_map[i + 1][j] == ' ')
		return (false);
	if (data->map.world_map[i - 1][j] == ' ')
		return (false);
	if (data->map.world_map[i][j + 1] == ' ')
		return (false);
	if (data->map.world_map[i][j - 1] == ' ')
		return (false);
	return (true);
}

bool	check_empty_and_zero(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	while (data->map.world_map[i])
	{
		j = 0;
		while (data->map.world_map[i][j])
		{
			if (data->map.world_map[i][j] == '0')
			{
				if (!char_checks(data, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_whole_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.world_map[i][j])
		{
			if (data->map.world_map[i][j] != '0' && \
				data->map.world_map[i][j] != '1' && \
				data->map.world_map[i][j] != 'N' && \
				data->map.world_map[i][j] != 'E' && \
				data->map.world_map[i][j] != 'S' && \
				data->map.world_map[i][j] != 'W' &&
				data->map.world_map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
