/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 15:05:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/03/09 14:01:03 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_player_direction(t_map *map, t_player *player, t_ipos *pos)
{
	player->loc.x = (double)pos->x + 0.5;
	player->loc.y = (double)pos->y + 0.5;
	if (map->world_map[pos->y][pos->x] == 'N')
	{
		player->plane.x = 0.666;
		player->plane.y = 0;
		player->direction.x = 0;
		player->direction.y = -1.0;
	}
	else if (map->world_map[pos->y][pos->x] == 'E')
	{
		player->plane.x = 0;
		player->plane.y = 0.666;
		player->direction.x = 1.0;
		player->direction.y = 0;
	}
	else if (map->world_map[pos->y][pos->x] == 'S')
	{
		player->plane.x = -0.666;
		player->plane.y = 0;
		player->direction.x = 0;
		player->direction.y = 1.0;
	}
	map->world_map[pos->y][pos->x] = '0';
}

static bool	check_players(t_data *data)
{
	t_ipos	pos;

	data->player.plane.x = 0;
	data->player.plane.y = -0.666;
	data->player.direction.x = -1.0;
	data->player.direction.y = 0;
	pos.y = 0;
	while (data->map.world_map[pos.y])
	{
		pos.x = 0;
		while (data->map.world_map[pos.y][pos.x])
		{
			if (ft_strchr("NESW", data->map.world_map[pos.y][pos.x]))
			{
				if (data->player.loc.x == (double)0 || \
					data->player.loc.y == (double)0)
					set_player_direction(&data->map, &data->player, &pos);
				else
					return (false);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (data->player.loc.x != 0 && data->player.loc.y != 0);
}

static bool	cnb(t_data *data, int x, int y, const char *illegal)
{
	if (ft_strchr(illegal, data->map.world_map[y + 1][x]))
		return (false);
	if (ft_strchr(illegal, data->map.world_map[y][x + 1]))
		return (false);
	return (true);
}

static bool	check_structure(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map.dimensions.y - 1)
	{
		x = 0;
		while (x < data->map.dimensions.x - 1)
		{
			if ((data->map.world_map[y][x] == ' ' && !cnb(data, x, y, "0NESW")) || \
				(data->map.world_map[y][x] == '0' && !cnb(data, x, y, " ")) || \
				(data->map.world_map[y][x] == 'N' && !cnb(data, x, y, " ")) || \
				(data->map.world_map[y][x] == 'E' && !cnb(data, x, y, " ")) || \
				(data->map.world_map[y][x] == 'S' && !cnb(data, x, y, " ")) || \
				(data->map.world_map[y][x] == 'W' && !cnb(data, x, y, " ")))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	validate_map(t_data *data)
{
	if (!check_players(data))
		return (false);
	if (!check_structure(data))
		return (false);
	return (true);
}
