/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 13:49:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/03 15:10:42 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize(t_data *data, int argc, char *argv[])
{
	data->argc = argc;
	data->argv = argv;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
	{
		printf("%s\n", "More arguments needed");
		return (EXIT_SUCCESS);
	}
	initialize(&data, argc, argv);
	parse_map(&data);
	// system("leaks cub3d");
	return (0);
}
