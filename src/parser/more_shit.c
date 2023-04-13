/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_shit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 16:56:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/13 17:03:27 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	fml(t_data *data, int *poep)
{
	char	*str;
	int		fd;

	fd = open(data->argv[1], O_RDONLY);
	if (!fd)
		return (ft_error("File descriptor failed", EXIT_FAILURE));
	str = get_next_line(fd);
	while (str)
	{
		if (ft_strncmp(str, "NO", 2) == 0)
			poep[0] += 1;
		else if (ft_strncmp(str, "SO", 2) == 0)
			poep[1] += 1;
		else if (ft_strncmp(str, "WE", 2) == 0)
			poep[2] += 1;
		else if (ft_strncmp(str, "EA", 2) == 0)
			poep[3] += 1;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (poep[0] != 1 || poep[1] != 1 || poep[2] != 1 || poep[3] != 1)
		return (false);
	return (true);
}

bool	count_textures(t_data *data)
{
	int		poep[4];

	ft_memset(poep, 0, sizeof(poep));
	if (!fml(data, poep))
		return (false);
	return (true);
}
