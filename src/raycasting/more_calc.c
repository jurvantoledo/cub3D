/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:57:56 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/13 15:58:18 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	calc_wall_hit(t_raycast *ray, t_player *player)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = player->loc.y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = player->loc.x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	return (wall_x);
}
