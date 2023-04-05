/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycaster.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 14:53:32 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/05 14:57:48 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//	In if statements: jump to next map square, 
//	either in x-direction, or in y-direction

//	In last if statement: Check if ray has hit a wall
static void	dda_algorithm(t_map *map, t_raycast *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->world_map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	get_walls(t_raycast *ray, t_player *player)
{
	ray->wall_x = player->loc.y + ray->perpwalldist * ray->raydir_y;
	if (ray->side == 0)
		ray->wall_x = player->loc.y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = player->loc.x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	if (!ray->side && ray->raydir_x >= 0)
		ray->side = 2;
	else if (!ray->side && ray->raydir_x < 0)
		ray->side = 3;
	else if (ray->side && ray->raydir_y >= 0)
		ray->side = 0;
	else
		ray->side = 1;
	if (ray->side == 3 || ray->side == 0)
		ray->wall_x = 1.0 - ray->wall_x;
}

void	ft_raycaster(t_data *data, t_player *player)
{
	int			index;
	t_map		*map;
	t_raycast	*ray;

	map = &data->map;
	ray = &data->ray;
	mlx_delete_image(data->mlx, data->foreground);
	data->foreground = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->foreground == NULL)
		exit(ft_free(data, EXIT_FAILURE));
	index = 0;
	while (index < WIDTH)
	{
		calc_ray_pos_dir(ray, player, index);
		init_ray_len(ray, player);
		dda_algorithm(map, ray);
		calc_line_plane(ray, player);
		get_walls(ray, player);
		get_wall_textures(ray, data->foreground, \
					data->textures[ray->side], index);
		index++;
	}
	if (mlx_image_to_window(data->mlx, data->foreground, 0, 0) < 0)
		exit(ft_free(data, EXIT_FAILURE));
}
