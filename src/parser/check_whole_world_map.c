/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_whole_world_map.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 15:44:50 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/05 11:43:49 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
