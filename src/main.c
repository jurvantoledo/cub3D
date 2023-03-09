/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/09 14:07:16 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	test(t_data *cub3d)
{
	(void)cub3d;
	int			index	= 0;
	t_player	*player	= &cub3d->player;
	t_map		*map	= &cub3d->map;
	ft_memset(cub3d->foreground->pixels, 0, cub3d->foreground->width * cub3d->foreground->height * sizeof(int));

	while (index < WIDTH)
	{
		//calculate ray position and direction
		double cameraX = 2 * index / (double)WIDTH - 1; //x-coordinate in camera space
		double rayDirX = player->direction.x + player->plane.x * cameraX;
		double rayDirY = player->direction.y + player->plane.y * cameraX;
		//which box of the map we're in
		int mapX = (int)player->loc.x;
		int mapY = (int)player->loc.y;
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
      	double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
      	double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

	  //what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->loc.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->loc.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->loc.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->loc.y) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (map->world_map[mapX][mapY] == '1') hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(side == 0)
		perpWallDist = (mapX - player->loc.x + (1 - stepX) / 2) / rayDirX;
      else          
	  	perpWallDist = (mapY - player->loc.y + (1 - stepY) / 2) / rayDirY;
		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;
		//choose wall color
		int color = 0x00000000;
		if (map->world_map[mapY][mapX] == '1')
			color = 0x555555FF;
		if (color && side == 1)
			color = 0x999999FF;
		//draw the pixels of the stripe as a vertical line
		// verLine(x, drawStart, drawEnd, color);
		if (drawEnd < 0)
			drawEnd = HEIGHT - 1;

		double wallX; //where exactly the wall was hit
		if(side == 0) wallX = player->loc.y + perpWallDist * rayDirY;
		else          wallX = player->loc.x + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		if (index == WIDTH / 2) {
			// printf("%d , %d , %d, 0x%X\n", index, drawStart, drawEnd, color);
			// printf("plane  x %.2f , y %.2f \n", player->plane.x, player->plane.y);
			// printf("player x %.2f , y %.2f \n", player->direction.x, player->direction.y);
			// printf("wall x: %.2f\n", wallX);
			if (!side && rayDirX >= 0)
				color = 0xFF0000FF; // north
			else if (!side && rayDirX < 0)
				color = 0x00FF00FF; // south
			else if (side && rayDirY >= 0)
				color = 0x0000FFFF; // west
			else
				color = 0xFFFF00FF; // east
		}
		if (drawEnd < 0 || drawEnd > HEIGHT || drawStart < 0 || drawStart > HEIGHT)
		{
			index++;
			continue ;
		}
		int	lol = drawStart;
		while (lol < drawEnd)
		{
			mlx_put_pixel(cub3d->foreground, index, lol, color);
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
	{
		printf("%s\n", "More arguments needed");
		return (EXIT_FAILURE);
	}
	initialize(&data, argc, argv);
	parse_map(&data);
	validate_map(&data);
	find_textures(&data);
	setup(&data);
	mlx_image_to_window(data.mlx, data.background, 0, 0);
	mlx_image_to_window(data.mlx, data.foreground, 0, 0);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
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
