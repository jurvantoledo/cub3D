/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/30 17:02:32 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	arg_checker(char **argv)
{
	if (ft_strlen(argv[1]) < 5)
		return (false);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
		return (false);
	return (true);
}

static void	initialize(t_data *data, int argc, char *argv[])
{
	data->argc = argc;
	data->argv = argv;
	data->plane.x = 0;
	data->plane.y = -0.66;
	data->move_speed = 0.050;
	data->rotation_speed = 0.10;
}

static bool	init_parsing_stuff(t_data *data)
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
	if (!arg_checker(argv))
	{
		ft_error("Invalid filename", false);
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
