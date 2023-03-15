/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/15 16:36:21 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	test(t_data *data)
{
	(void)data;
	int			index;
	t_player	*player = &data->player;
	t_map		*map = &data->map;
	t_raycast	*ray = &data->ray;

	ft_memset(data->foreground->pixels, 0, data->foreground->width * \
				data->foreground->height * sizeof(int));
	index = 0;
	while (index < WIDTH)
	{
		//calculate ray position and direction
		ray->camera_x = 2 * index / (double)WIDTH - 1; //x-coordinate in camera space
		ray->raydir_x = player->direction.x + player->plane.x * ray->camera_x;
		ray->raydir_y = player->direction.y + player->plane.y * ray->camera_x;
		//which box of the map we're in
		ray->map_x = (int)player->loc.x;
		ray->map_y = (int)player->loc.y;
		//length of ray from current position to next x or y-side
      	ray->deltadist_x = sqrt(1 + (ray->raydir_y * ray->raydir_y) / (ray->raydir_x * ray->raydir_x));
      	ray->deltadist_y = sqrt(1 + (ray->raydir_x * ray->raydir_x) / (ray->raydir_y * ray->raydir_y));

	  //what direction to step in x or y-direction (either +1 or -1)
		int hit = 0; //was there a wall hit?
		//was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(ray->raydir_x < 0)
		{
			ray->step_x = -1;
			ray->sidedist_x = (player->loc.x - ray->map_x) * ray->deltadist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->sidedist_x = (ray->map_x + 1.0 - player->loc.x) * ray->deltadist_x;
		}
		if (ray->raydir_y < 0)
		{
			ray->step_y = -1;
			ray->sidedist_y = (player->loc.y - ray->map_y) * ray->deltadist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->sidedist_x = (ray->map_y + 1.0 - player->loc.y) * ray->deltadist_y;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
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
			//Check if ray has hit a wall
			if (map->world_map[ray->map_x][ray->map_y] == '1') hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(ray->side == 0)
		ray->perpwalldist = (ray->map_x - player->loc.x + (1 - ray->step_x) / 2) / ray->raydir_x;
      else          
	  	ray->perpwalldist = (ray->map_y - player->loc.y + (1 - ray->step_y) / 2) / ray->raydir_y;
		//Calculate height of line to draw on screen
		ray->line_height = (int)(HEIGHT / ray->perpwalldist);
		//calculate lowest and highest pixel to fill in current stripe
		ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
		if (ray->draw_start < 0) ray->draw_start = 0;
		ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
		if (ray->draw_end >= HEIGHT) ray->draw_end = HEIGHT - 1;
		//choose wall color
		int color = 0x00000000;
		if (map->world_map[ray->map_x][ray->map_y] == '1')
			color = 0x555555FF;
		if (color && ray->side == 1)
			color = 0x999999FF;
		//draw the pixels of the stripe as a vertical line
		// verLine(x, drawStart, drawEnd, color);
		if (ray->draw_end < 0)
			ray->draw_end = HEIGHT - 1;

		if(ray->side == 0) ray->wall_x = player->loc.y + ray->perpwalldist * ray->raydir_y;
		else          ray->wall_x = player->loc.x + ray->perpwalldist * ray->raydir_x;
		ray->wall_x -= floor(ray->wall_x);

		if (index == WIDTH / 2) {
			// printf("%d , %d , %d, 0x%X\n", index, drawStart, drawEnd, color);
			// printf("plane  x %.2f , y %.2f \n", player->plane.x, player->plane.y);
			// printf("player x %.2f , y %.2f \n", player->direction.x, player->direction.y);
			// printf("wall x: %.2f\n", wallX);
			if (!ray->side && ray->raydir_x >= 0)
				color = 0xFF0000FF; // north
			else if (!ray->side && ray->raydir_x < 0)
				color = 0x00FF00FF; // south
			else if (ray->side && ray->raydir_y >= 0)
				color = 0x0000FFFF; // west
			else
				color = 0xFFFF00FF; // east
		}
		if (ray->draw_end < 0 || ray->draw_end > HEIGHT || ray->draw_start < 0 || ray->draw_start > HEIGHT)
		{
			index++;
			continue ;
		}
		int	lol = ray->draw_start;
		while (lol < ray->draw_end)
		{
			mlx_put_pixel(data->foreground, index, lol, color);
			lol++;
		}
		index++;
	}
}

void	initialize(t_data *data, int argc, char *argv[])
{
	data->argc = argc;
	data->argv = argv;
	data->plane.x = 0;
	data->plane.y = -0.66;
	data->move_speed = 0.045;
	data->rotation_speed = 0.05;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc < 2 || argc > 2)
		return (ft_error("Invalid amount of arguments", EXIT_FAILURE));
	initialize(&data, argc, argv);
	parse_map(&data);
	validate_map(&data);
	find_textures(&data);
	setup(&data);
	mlx_image_to_window(data.mlx, data.background, 0, 0);
	mlx_image_to_window(data.mlx, data.foreground, 0, 0);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	ft_free(&data);
	mlx_terminate(data.mlx);
	// system("leaks cub3d");
	return (EXIT_SUCCESS);
}

// // -----------------------------------------------------------------------------

// int32_t main(int32_t argc, const char* argv[])
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
