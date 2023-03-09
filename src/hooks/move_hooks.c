/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_hooks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:30:04 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/09 12:54:46 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	move_forward(t_data *data, t_player *player)
{
	double	new_x;
	double	new_y;

	player->loc.x += player->direction.x * data->move_speed;
	player->loc.y += player->direction.y * data->move_speed;
}

static void	move_back(t_data *data, t_player *player)
{
	double	new_x;
	double	new_y;

	player->loc.x -= player->direction.x * data->move_speed;
	player->loc.y -= player->direction.y * data->move_speed;
}

static void	move_left(t_data *data, t_player *player)
{
	player->loc.x += player->direction.y * data->move_speed;
	player->loc.y += -player->direction.x * data->move_speed;
}

static void	move_right(t_data *data, t_player *player)
{
	player->loc.x += -player->direction.y * data->move_speed;
	player->loc.y += player->direction.x * data->move_speed;
}

void	exec_moves(t_data *data, t_player *player)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_forward(data, player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_back(data, player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_left(data, player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_right(data, player);
}
