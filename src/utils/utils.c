/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 17:00:35 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/29 17:45:54 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_colors(char **arr)
{
	if ((ft_atoi(arr[0]) > 255 || ft_atoi(arr[0]) < 0) || \
		(ft_atoi(arr[1]) > 255 || ft_atoi(arr[1]) < 0) || \
		(ft_atoi(arr[2]) > 255 || ft_atoi(arr[2]) < 0))
		return (true);
	return (false);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
