/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 11:42:44 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/08 12:02:52 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	setup(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!data->mlx)
		ft_error("failed initializing mlx", EXIT_FAILURE);
	data->background = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->background)
		ft_error("failed creating background image", EXIT_FAILURE);
	data->foreground = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->foreground)
		ft_error("failed creating foreground image", EXIT_FAILURE);
	return (true);
}
