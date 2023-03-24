/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 15:50:31 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/24 11:06:13 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_for_double_komma(char *str, char **arr)
{
	int		i;
	int		count;
	int		arr_len;

	arr_len = ft_arraylen(arr);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2 && arr_len == 3)
		return (true);
	return (false);
}

static bool	check_for_data(t_data *data)
{
	if ((data->map.texture[0] == NULL || data->map.texture[1] == NULL) \
		|| data->map.texture[2] == NULL || data->map.texture[3] == NULL \
		|| data->map.floor == 0 || data->map.ceiling == 0)
		return (false);
	return (true);
}

static bool	check_keys(t_data *data, char *mapline, char *key)
{
	if (ft_strncmp(mapline, key, 2) == 0 || ft_strncmp(mapline, key, 1) == 0)
		return (true);
	return (false);
}

int	check_key_data(t_data *data)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < 6)
	{
		if (check_keys(data, data->map.raw_map[index], "NO") || \
			check_keys(data, data->map.raw_map[index], "SO") || \
			check_keys(data, data->map.raw_map[index], "WE") || \
			check_keys(data, data->map.raw_map[index], "EA") || \
			check_keys(data, data->map.raw_map[index], "F") || \
			check_keys(data, data->map.raw_map[index], "C"))
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
