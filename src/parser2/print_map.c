/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 11:31:35 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/22 17:01:04 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_parsed_values(t_data *data)
{
	printf("The NO texture: %s\n", data->map.texture[0]);
	printf("The SO texture: %s\n", data->map.texture[1]);
	printf("The WE texture: %s\n", data->map.texture[2]);
	printf("The EA texture: %s\n", data->map.texture[3]);
	printf("The floor: %d\n", data->map.floor);
	printf("The ceiling: %d\n", data->map.ceiling);
	printf("The height: %d\n", data->map.height);
	printf("The width: %d\n", data->map.width);
}

void	print_raw_map(t_data *data)
{
	int	index;

	index = 0;
	while (data->map.raw_map[index])
	{
		printf("the raw map lines: %s\n", data->map.raw_map[index]);
		index++;
	}
}

void	print_world_map(t_data *data)
{
	int	index;

	index = 0;
	while (data->map.world_map[index])
	{
		printf("the world map lines: %s\n", data->map.world_map[index]);
		index++;
	}
}
