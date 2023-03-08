/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:16:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/08 14:34:22 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook(void *param)
{
	t_data		*data;
	t_player	*player;
	int			x;
	int			y;

	data = (t_data *)param;
	player = &data->player;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) || \
		mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || \
		mlx_is_key_down(data->mlx, MLX_KEY_LEFT) || \
		mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		exec_moves(data, player);
	test(data);
}

