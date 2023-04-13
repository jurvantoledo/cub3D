/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_elements.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 10:57:31 by jvan-tol      #+#    #+#                 */
/*   Updated: 2023/04/13 16:56:52 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_value(char *str)
{
	char	**split_komma;
	int		val;
	char	*new_str;

	if (!check_floor_ceiling_data(str))
		return (0);
	new_str = ft_remove_spaces_and_key(str);
	split_komma = ft_split(new_str, ',');
	if (!split_komma)
		return (0);
	if (!check_for_double_komma(str, split_komma) || \
		check_colors(split_komma) || !check_split_val(split_komma))
	{
		free_arr(split_komma);
		return (0);
	}
	val = (ft_atoi(split_komma[0]) << 24) | \
			(ft_atoi(split_komma[1]) << 16) | (ft_atoi(split_komma[2]) << 8) | \
			0x000000FF;
	free(new_str);
	free_arr(split_komma);
	return (val);
}

int	get_floor_ceiling(t_data *data, char *key)
{
	int		val;
	char	*str;
	int		fd;

	fd = open(data->argv[1], O_RDONLY);
	if (!fd)
		return (0);
	str = get_next_line(fd);
	val = 0;
	while (str)
	{
		if (ft_strncmp(str, key, 1) == 0)
			val = get_value(str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (val);
}

static char	*parse_textures_new(char *str)
{
	char	*val;
	char	**new_str;

	new_str = ft_split(str, ' ');
	if (!new_str || !new_str[1])
		return (NULL);
	val = ft_strdup(new_str[1]);
	if (!val)
	{
		free_arr(new_str);
		return (NULL);
	}
	val[ft_strlen(new_str[1]) - 1] = '\0';
	free_arr(new_str);
	return (val);
}

// bool	fml(t_data *data, int *poep)
// {
// 	char	*str;
// 	int		fd;

// 	fd = open(data->argv[1], O_RDONLY);
// 	if (!fd)
// 		return (ft_error("File descriptor failed", EXIT_FAILURE));
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		if (ft_strncmp(str, "NO", 2) == 0)
// 			poep[0] += 1;
// 		else if (ft_strncmp(str, "SO", 2) == 0)
// 			poep[1] += 1;
// 		else if (ft_strncmp(str, "WE", 2) == 0)
// 			poep[2] += 1;
// 		else if (ft_strncmp(str, "EA", 2) == 0)
// 			poep[3] += 1;
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// 	if (poep[0] != 1 || poep[1] != 1 || poep[2] != 1 || poep[3] != 1)
// 		return (false);
// 	return (true);
// }

// static bool	count_textures(t_data *data)
// {
// 	int		poep[4];

// 	ft_memset(poep, 0, sizeof(poep));
// 	if (test_lol(data, poep) == false)
// 		return (false);
// 	return (true);
// }

char	*get_textures(t_data *data, char *key)
{
	char	*str;
	char	*val;
	int		fd;

	if (!count_textures(data))
		return (NULL);
	fd = open(data->argv[1], O_RDONLY);
	if (!fd)
		return (NULL);
	str = get_next_line(fd);
	printf("%s\n", key);
	while (str)
	{
		if (ft_strncmp(str, key, ft_strlen(key)) == 0)
			val = parse_textures_new(str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (val);
}
