/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:11:14 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/29 14:23:40 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//x-coordinate in camera space
void	calc_ray_pos_dir(t_raycast *ray, t_player *player, int i)
{
	ray->camera_x = 2 * i / (double)WIDTH - 1;
	ray->raydir_x = player->direction.x + player->plane.x * ray->camera_x;
	ray->raydir_y = player->direction.y + player->plane.y * ray->camera_x;
	ray->map_x = (int)player->loc.x;
	ray->map_y = (int)player->loc.y;
	ray->deltadist_x = sqrt(1 + (ray->raydir_y * ray->raydir_y) / \
						(ray->raydir_x * ray->raydir_x));
	ray->deltadist_y = sqrt(1 + (ray->raydir_x * ray->raydir_x) / \
						(ray->raydir_y * ray->raydir_y));
}

void	init_ray_len(t_raycast *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->loc.x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->loc.x) * \
						ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->loc.y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->loc.y) * ray->deltadist_y;
	}
}

// Calculate distance projected on camera direction. 
// This is the shortest distance from the point where the wall is 
// hit to the camera plane.

// Euclidean to center camera point would give fisheye effect!
// This can be computed as:
// (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, 
// or same formula with Y for size == 1, 
// but can be simplified to the code below 
// thanks to how sideDist and deltaDist are computed:
// because they were left scaled to |rayDir|. sideDist 
// is the entire length of the ray above after the multiple
// steps, but we subtract deltaDist once 
// because one step more into the wall was taken above.
void	calc_line_plane(t_raycast *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - player->loc.x + \
							(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - player->loc.y + \
							(1 - ray->step_y) / 2) / ray->raydir_y;
	ray->line_height = (int)(HEIGHT / ray->perpwalldist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->draw_end < 0)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->loc.y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = player->loc.x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	get_vertical_line_height(t_raycast *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perpwalldist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
}
