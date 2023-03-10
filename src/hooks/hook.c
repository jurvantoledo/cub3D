/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:16:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/13 16:26:03 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook(void *param)
{
	t_data		*data;
	t_player	*player;
	t_map		*map;
	t_raycast	*ray;

	data = (t_data *)param;
	player = &data->player;
	map = &data->map;
	ray = &data->ray;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_forward(data, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_back(data, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_left(data, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_right(data, player);
	ft_raycaster(data);
}
