/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_hooks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:30:04 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/24 11:20:05 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_data *data, t_player *player)
{
	double	x;
	double	y;

	x = player->loc.x + player->direction.x * data->move_speed;
	y = player->loc.y + player->direction.y * data->move_speed;
	if (data->map.world_map[(int)floor(x)][(int)floor(player->loc.y)] != '1')
		player->loc.x += player->direction.x * data->move_speed;
	if (data->map.world_map[(int)floor(player->loc.x)][(int)floor(y)] != '1')
		player->loc.y += player->direction.y * data->move_speed;
}

void	move_back(t_data *data, t_player *player)
{
	double	x;
	double	y;

	x = player->loc.x - player->direction.x * data->move_speed;
	y = player->loc.y - player->direction.y * data->move_speed;
	if (data->map.world_map[(int)floor(x)][(int)floor(player->loc.y)] != '1')
		player->loc.x -= player->direction.x * data->move_speed;
	if (data->map.world_map[(int)floor(player->loc.x)][(int)floor(y)] != '1')
		player->loc.y -= player->direction.y * data->move_speed;
}

void	move_left(t_data *data, t_player *player)
{
	double	x;
	double	y;

	x = player->loc.x + (player->direction.y * data->move_speed);
	y = player->loc.y + (-player->direction.x * data->move_speed);
	if (data->map.world_map[(int)floor(x)][(int)floor(player->loc.y)] != '1')
		player->loc.x += player->direction.y * data->move_speed;
	if (data->map.world_map[(int)floor(player->loc.x)][(int)floor(y)] != '1')
		player->loc.y += -player->direction.x * data->move_speed;
}

void	move_right(t_data *data, t_player *player)
{
	double	x;
	double	y;

	x = player->loc.x + (-player->direction.y * data->move_speed);
	y = player->loc.y + (player->direction.x * data->move_speed);
	if (data->map.world_map[(int)floor(x)][(int)floor(player->loc.y)] != '1')
		player->loc.x += -player->direction.y * data->move_speed;
	if (data->map.world_map[(int)floor(player->loc.x)][(int)floor(y)] != '1')
		player->loc.y += player->direction.x * data->move_speed;
}

