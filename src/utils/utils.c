/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 17:00:35 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/13 16:39:59 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_floor_ceiling_data(char *str)
{
	if ((str[0] == 'F' && str[1] == ' ') || \
		(str[0] == 'C' && str[1] == ' '))
	{
		return (true);
	}
	return (false);
}

char	*ft_remove_spaces_and_key(char *str)
{
	int		i;
	int		non_space;
	int		key_len;
	char	*trimmed;

	key_len = 0;
	while (str[key_len] != ' ' && ft_isalpha(str[key_len]))
		key_len++;
	non_space = 0;
	i = key_len;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str[non_space] = str[i];
			non_space++;
		}
		i++;
	}
	str[non_space] = '\0';
	trimmed = ft_strtrim(str, "\n");
	if (!trimmed)
		return (NULL);
	return (trimmed);
}

bool	check_location(t_data *data, double x, double y)
{
	if (data->map.world_map[(int)floor(y)][(int)floor(x)] == '1')
		return (false);
	return (true);
}

bool	check_colors(char **arr)
{
	if ((ft_atoi(arr[0]) > 255 || ft_atoi(arr[0]) < 0) || \
		(ft_atoi(arr[1]) > 255 || ft_atoi(arr[1]) < 0) || \
		(ft_atoi(arr[2]) > 255 || ft_atoi(arr[2]) < 0))
		return (true);
	return (false);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
