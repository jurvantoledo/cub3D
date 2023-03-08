/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 15:05:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/08 15:15:18 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	set_player_direction(t_map *map, t_player *player, t_ipos *pos)
// {
// 	player->loc.x = (double)pos->x + 0.5;
// 	player->loc.y = (double)pos->y + 0.5;
// 	if (map->world_map[pos->y][pos->x] == 'N')
// 	{
// 		player->plane.x = 0.666;
// 		player->plane.y = 0;
// 		player->direction.x = 0;
// 		player->direction.y = -1.0;
// 	}
// 	else if (map->world_map[pos->y][pos->x] == 'E')
// 	{
// 		player->plane.x = 0;
// 		player->plane.y = 0.666;
// 		player->direction.x = 1.0;
// 		player->direction.y = 0;
// 	}
// 	else if (map->world_map[pos->y][pos->x] == 'S')
// 	{
// 		player->plane.x = -0.666;
// 		player->plane.y = 0;
// 		player->direction.x = 0;
// 		player->direction.y = 1.0;
// 	}
// 	map->world_map[pos->y][pos->x] = '0';
// }

// static bool	check_players(t_data *cub3d)
// {
// 	t_ipos	pos;

// 	cub3d->player.plane.x = 0;
// 	cub3d->player.plane.y = -0.666;
// 	cub3d->player.direction.x = -1.0;
// 	cub3d->player.direction.y = 0;
// 	pos.y = 0;
// 	while (cub3d->map.world_map[pos.y])
// 	{
// 		pos.x = 0;
// 		while (cub3d->map.world_map[pos.y][pos.x])
// 		{
// 			if (ft_strchr("NESW", cub3d->map.world_map[pos.y][pos.x]))
// 			{
// 				if (cub3d->player.loc.x == (double)0 || \
// 					cub3d->player.loc.y == (double)0)
// 					set_player_direction(&cub3d->map, &cub3d->player, &pos);
// 				else
// 					return (false);
// 			}
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// 	return (cub3d->player.loc.x != 0 && cub3d->player.loc.y != 0);
// }

// static bool	cnb(t_data *cub3d, int x, int y, const char *illegal)
// {
// 	if (ft_strchr(illegal, cub3d->map.world_map[y + 1][x]))
// 		return (false);
// 	if (ft_strchr(illegal, cub3d->map.world_map[y][x + 1]))
// 		return (false);
// 	return (true);
// }

// static bool	check_structure(t_data *cub3d)
// {
// 	int		y;
// 	int		x;

// 	y = 0;
// 	while (y < cub3d->map.dimensions.y - 1)
// 	{
// 		x = 0;
// 		while (x < cub3d->map.dimensions.x - 1)
// 		{
// 			if ((cub3d->map.world_map[y][x] == ' ' && !cnb(cub3d, x, y, "0NESW")) || \
// 				(cub3d->map.world_map[y][x] == '0' && !cnb(cub3d, x, y, " ")) || \
// 				(cub3d->map.world_map[y][x] == 'N' && !cnb(cub3d, x, y, " ")) || \
// 				(cub3d->map.world_map[y][x] == 'E' && !cnb(cub3d, x, y, " ")) || \
// 				(cub3d->map.world_map[y][x] == 'S' && !cnb(cub3d, x, y, " ")) || \
// 				(cub3d->map.world_map[y][x] == 'W' && !cnb(cub3d, x, y, " ")))
// 				return (false);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (true);
// }

// bool	validate_map(t_data *data)
// {
// 	if (!check_players(data))
// 		return (false);
// 	if (!check_structure(data))
// 		return (false);
// 	return (true);
// }

bool	validate_map(t_data *data)
{
	return (true);
}