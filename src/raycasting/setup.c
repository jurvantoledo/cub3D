/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 11:42:44 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/24 11:34:04 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_background(mlx_image_t *image, t_map *map)
{
	int	i;

	i = 0;
	while (i < HEIGHT * WIDTH / 2)
	{
		mlx_put_pixel(image, i % WIDTH, i / WIDTH, map->ceiling);
		mlx_put_pixel(image, i % WIDTH, i / WIDTH + \
			HEIGHT / 2, map->floor);
		i++;
	}
}

bool	setup(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (ft_error("failed initializing mlx", EXIT_FAILURE));
	data->background = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->background)
		return (ft_error("failed creating background image", EXIT_FAILURE));
	data->foreground = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->foreground)
		return (ft_error("failed creating foreground image", EXIT_FAILURE));
	set_background(data->background, &data->map);
	return (true);
}
