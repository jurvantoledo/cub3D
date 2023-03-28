/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 16:13:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/28 15:12:08 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_free_map(t_map *map)
{
	int	i;

	free_arr(map->raw_map);
	i = 0;
	while (i)
	{
		free(map->texture[i]);
		i++;
	}
}

static void	ft_free_textures(mlx_texture_t *textures[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (textures[i])
			mlx_delete_texture(textures[i]);
		i++;
	}
}

static void	ft_free_bg_fg(t_data *data)
{
	if (data->background)
		mlx_delete_image(data->mlx, data->background);
	if (data->foreground)
		mlx_delete_image(data->mlx, data->foreground);
}

int	ft_free(t_data *data, int exit_code)
{
	ft_free_map(&data->map);
	ft_free_textures(data->textures);
	ft_free_bg_fg(data);
	if (data->mlx)
		mlx_terminate(data->mlx);
	return (exit_code);
}
