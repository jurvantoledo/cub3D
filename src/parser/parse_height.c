/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_height.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 16:26:29 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/22 16:53:53 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_height_new(t_data *data)
{
	int	index;
	int	lines;

	index = check_key_data(data);
	lines = 0;
	while (data->map.raw_map[index])
	{
		lines++;
		index++;
	}
	return (lines);
}
