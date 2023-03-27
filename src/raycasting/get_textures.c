/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_textures.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 14:40:40 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/27 15:53:34 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_wall_textures(t_raycast *ray, mlx_image_t *image, \
	mlx_texture_t *texture, int w)
{
	t_ipos	oc;
	t_ipos	heights;
	t_ipos	pixel_location;
	int		index;

	oc.x = 0;
	heights.y = ray->draw_end - ray->draw_start;
	if (heights.y > HEIGHT)
		oc.x = (heights.y - HEIGHT) / 2;
	heights.x = ray->draw_end - ray->draw_start;
	if (heights.x > HEIGHT)
		heights.x = HEIGHT;
	pixel_location.x = (int)((texture->width) * ray->wall_x);
	index = 0;
	while (index < heights.x)
	{
		pixel_location.y = (int)((((float)texture->height \
			/ heights.y)) * (index + oc.x));
		oc.y = *(int *)(&texture->pixels[(pixel_location.y * texture->width \
			+ pixel_location.x) * sizeof(int)]);
		oc.y = ((oc.y >> 24) & 0xff) | ((oc.y << 8) & 0xff0000) | \
			((oc.y >> 8) & 0xff00) | ((oc.y << 24) & 0xff000000);
		mlx_put_pixel(image, w, (HEIGHT - heights.x - 1) / 2 + index, oc.y);
		index++;
	}
}
