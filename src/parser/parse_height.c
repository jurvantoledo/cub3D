/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_height.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 16:26:29 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/06 13:33:46 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_height_new(t_data *data)
{
	int	index;
	int	lines;

	if (check_key_data(data) != 0)
		index = check_key_data(data);
	else
		return (0);
	lines = 0;
	while (data->map.raw_map[index])
	{
		lines++;
		index++;
	}
	return (lines);
}
