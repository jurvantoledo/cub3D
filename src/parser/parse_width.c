/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 16:27:19 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/06 13:33:56 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_width(char *str, int prev_width, int total_width)
{
	int	width;

	width = 0;
	while (str[width])
	{
		if (width > prev_width && total_width < width)
		{
			total_width = width;
		}
		width++;
	}
	prev_width = width;
	return (total_width);
}

int	parse_width_new(t_data *data)
{
	int	prev_width;
	int	total_width;
	int	index;

	if (check_key_data(data) != 0)
		index = check_key_data(data);
	else
		return (0);
	prev_width = 0;
	total_width = 0;
	while (data->map.raw_map[index])
	{
		total_width = get_width(data->map.raw_map[index], \
						prev_width, total_width);
		index++;
	}
	return (total_width + 1);
}
