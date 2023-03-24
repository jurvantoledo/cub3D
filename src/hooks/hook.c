/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:16:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/24 17:06:11 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	turn_hooks(t_data *data, t_player *player)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		look_left(data, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		look_right(data, player);
}

static void	move_hooks(t_data *data, t_player *player)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward(data, player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_back(data, player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data, player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data, player);
}

void	hook(void *param)
{
	t_data		*data;
	t_player	*player;

	data = (t_data *)param;
	player = &data->player;
	move_hooks(data, player);
	turn_hooks(data, player);
	ft_raycaster(data);
}
