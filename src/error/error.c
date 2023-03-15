/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 18:41:29 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/15 16:10:54 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_error(char *str, int exit_code)
{
	ft_putstr_fd("Error:\n", STDERR_FILENO);
	perror(str);
	return (exit_code);
}
