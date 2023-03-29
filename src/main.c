/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/29 17:48:33 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize(t_data *data, int argc, char *argv[])
{
	data->argc = argc;
	data->argv = argv;
	data->plane.x = 0;
	data->plane.y = -0.66;
	data->move_speed = 0.045;
	data->rotation_speed = 0.05;
}

bool	init_parsing_stuff(t_data *data)
{
	if (!parse_map(data) || !validate_map(data) || !check_world_map(data))
		return (ft_error("Map Error", false));
	if (!find_textures(data))
		return (ft_error("Texture Error", false));
	return (true);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc < 2 || argc > 2)
	{
		ft_error("Invalid amount of arguments", false);
		return (EXIT_FAILURE);
	}
	initialize(&data, argc, argv);
	if (!init_parsing_stuff(&data))
		return (ft_free(&data, EXIT_FAILURE));
	if (!setup(&data))
		return (ft_free(&data, EXIT_FAILURE));
	if (mlx_image_to_window(data.mlx, data.background, 0, 0) < 0 || \
		mlx_loop_hook(data.mlx, &hook, &data) == false)
		return (ft_free(&data, EXIT_FAILURE));
	mlx_loop(data.mlx);
	return (ft_free(&data, EXIT_SUCCESS));
}
