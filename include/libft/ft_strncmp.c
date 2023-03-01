/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:43:44 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/06 12:39:29 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	idx;

	idx = 0;
	while (idx < num)
	{
		if (str1[idx] == '\0' || str2[idx] == '\0')
			return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
		else if (str1[idx] != str2[idx])
		{
			return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
		}
		idx++;
	}
	return (0);
}
