/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   look_hooks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 15:50:09 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/30 16:48:37 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	look_left(t_data *data, t_player *player)
{
	double	old_direction_x;
	double	old_plane;

	old_direction_x = player->direction.x;
	old_plane = player->plane.x;
	player->direction.x = player->direction.x * cos(-data->rotation_speed) - \
							player->direction.y * sin(-data->rotation_speed);
	player->direction.y = old_direction_x * sin(-data->rotation_speed) + \
							player->direction.y * cos(-data->rotation_speed);
	player->plane.x = player->plane.x * cos(-data->rotation_speed) - \
						player->plane.y * sin(-data->rotation_speed);
	player->plane.y = old_plane * sin(-data->rotation_speed) + \
						player->plane.y * cos(-data->rotation_speed);
}

void	look_right(t_data *data, t_player *player)
{
	double	old_direction_x;
	double	old_plane;

	old_direction_x = player->direction.x;
	old_plane = player->plane.x;
	player->direction.x = player->direction.x * cos(data->rotation_speed) - \
							player->direction.y * sin(data->rotation_speed);
	player->direction.y = old_direction_x * sin(data->rotation_speed) + \
							player->direction.y * cos(data->rotation_speed);
	player->plane.x = player->plane.x * cos(data->rotation_speed) - \
						player->plane.y * sin(data->rotation_speed);
	player->plane.y = old_plane * sin(data->rotation_speed) + \
						player->plane.y * cos(data->rotation_speed);
}
