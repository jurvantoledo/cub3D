#include "../../include/cub3d.h"

static int get_value(t_data *data, char *str)
{
    char **split_str;
    char **split_komma;
    int *val;

    split_str = ft_split(str, ' ');
    if (!split_str)
        return (0);
    split_komma = ft_split(split_str[1], ',');
    if (!split_komma)
        return (0);
    free_arr(split_str);
    val = malloc(sizeof(int));
    if (!val)
        return (0);
    val[0] = (ft_atoi(split_komma[0]) << 24) |
             (ft_atoi(split_komma[1]) << 16) | (ft_atoi(split_komma[2]) << 8) |
             0x000000FF;
    free_arr(split_komma);
    return (val[0]);
}


int get_floor_ceiling(t_data *data, char *key)
{
    int val;
    char *str;
    int fd;

    fd = open(data->argv[1], O_RDONLY);
    str = get_next_line(fd);
    val = 0;
    while (str)
    {
        if (ft_strncmp(str, key, 1) == 0)
        {
            val = get_value(data, str);
        }
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (val);
}

static char *parse_textures_new(t_data *data, char *str)
{
    char *val;
    char **new_str;

    new_str = ft_split(str, ' ');
    if (!new_str)
        return (NULL);
    val = ft_strdup(new_str[1]);
    val[ft_strlen(new_str[1]) - 1] = '\0';
    free_arr(new_str);
    return (val);
}

char *get_textures(t_data *data, char *key)
{
    char *str;
    char *val;
    int fd;

    fd = open(data->argv[1], O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        if (ft_strncmp(str, key, 2) == 0)
            val = parse_textures_new(data, str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (val);
}