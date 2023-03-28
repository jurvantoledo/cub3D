/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 18:41:29 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/28 15:24:10 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	ft_error(char *str, bool ret)
{
	ft_putstr_fd("Error:\n", STDERR_FILENO);
	perror(str);
	return (ret);
}
