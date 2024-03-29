/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:47:45 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/05 12:11:03 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	load_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->textures[i] = mlx_load_png(data->map.texture[i]);
		if (!data->textures[i])
			return (false);
		i++;
	}
	return (true);
}

bool	find_textures(t_data *data)
{
	if (!load_textures(data))
		return (false);
	return (true);
}
