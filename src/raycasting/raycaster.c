/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycaster.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 14:53:32 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/13 16:36:22 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_vert_line(t_data *data, t_raycast *ray, int i, int color)
{
	int	lol;

	lol = ray->draw_start;
	while (lol < ray->draw_end)
	{
		mlx_put_pixel(data->foreground, i, lol, color);
		lol++;
	}
}

static bool	wtf(t_raycast *ray)
{
	if (ray->draw_end < 0 || ray->draw_end > HEIGHT || ray->draw_start < 0 || ray->draw_start > HEIGHT)
	{
		return (true);
	}
	return (false);
}

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
		if (map->world_map[ray->map_x][ray->map_y] == '1')
			hit = 1;
	}
}

// Choose wall color
static int	get_wall_colors(t_map *map, t_raycast *ray)
{
	int			color;

	color = 0x00000000;
	if (map->world_map[ray->map_x][ray->map_y] == '1')
			color = 0x555555FF;
	if (color && ray->side == 1)
		color = 0x999999FF;
	return (color);
}

int	get_colors(int i, t_raycast *ray)
{
	int	color;

	if (i == WIDTH / 2)
	{
		if (!ray->side && ray->raydir_x >= 0)
			color = 0xFF0000FF; // north
		else if (!ray->side && ray->raydir_x < 0)
			color = 0x00FF00FF; // south
		else if (ray->side && ray->raydir_y >= 0)
			color = 0x0000FFFF; // west
		else
			color = 0xFFFF00FF; // east
	}
	return (color);
}

void	ft_raycaster(t_data *data)
{
	int			i;
	int			c_test;
	int			colors;
	t_player	*player = &data->player;
	t_map		*map = &data->map;
	t_raycast	*ray = &data->ray;

	ft_memset(data->foreground->pixels, 0, data->foreground->width * \
			data->foreground->height * sizeof(int));
	i = 0;
	while (i < WIDTH)
	{
		calc_ray_pos_dir(ray, player, i);
		// calc_ray_len(ray, player);
		init_ray_len(ray, player);
		dda_algorithm(map, ray);
		calc_line_plane(ray, player);
		calc_line_height(ray);
		c_test = get_wall_colors(map, ray);
		if (ray->draw_end < 0)
			ray->draw_end = HEIGHT - 1;
		ray->wall_x = calc_wall_hit(ray, player);
		c_test = get_colors(i, ray);
		if (wtf(ray))
		{
			i++;
			continue ;
		}
		draw_vert_line(data, ray, i, c_test);
		i++;
	}
}
