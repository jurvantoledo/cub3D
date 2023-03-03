/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:10:18 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/03 16:03:02 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_map(t_data *data)
{
	parse_textures(data);
	parse_floor_ceiling(data);
	data->map.height = parse_height(data);
	printf("Map height: %d\n", data->map.height);
	data->map.width = parse_width(data);
	printf("Map width: %d\n", data->map.width);
}
