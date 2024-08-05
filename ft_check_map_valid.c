/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:00:57 by torandri          #+#    #+#             */
/*   Updated: 2024/08/05 14:11:19 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(t_data data)
{
	if (data.x <= 3 && data.y <= 3)
	{
		ft_printf("Error\nMap too little\n");
		free(data.file);
		return (1);
	}
	if (ft_check_map_error(data.x, data.y, data.file) == 1)
	{
		free(data.file);
		return (1);
	}
	if (ft_check_map_valid(&data) == 1)
	{
		free(data.file);
		return (1);
	}
	return (0);
}

void	fill_map(char **map, t_data *data, int beg_x, int beg_y)
{
	if (beg_x < 0 || beg_x >= data->x || beg_y < 0 || beg_y >= data->y)
		return ;
	if (map[beg_y][beg_x] == '1' || map[beg_y][beg_x] == 'F')
		return ;
	map[beg_y][beg_x] = 'F';
	fill_map(map, data, beg_x - 1, beg_y);
	fill_map(map, data, beg_x + 1, beg_y);
	fill_map(map, data, beg_x, beg_y - 1);
	fill_map(map, data, beg_x, beg_y + 1);
}

void	fill_map_on_ground(char **map, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (j < data->y)
	{
		i = 0;
		while (i < data->x)
		{
			if (map[j][i] == 'P')
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 1)
			break ;
		j++;
	}
	fill_map(map, data, i, j);
}

int	ft_check_map_valid(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = ft_tmp_map(&data->x, &data->y, data->file);
	fill_map_on_ground(map, data);
	j = 0;
	while (j < data->y)
	{
		i = 0;
		while (i < data->x)
		{
			if (map[j][i] == 'P' || map[j][i] == 'C' || map[j][i] == 'E')
			{
				ft_printf("Error\nNot a valid map, there is no way.\n");
				ft_free_map(map, data->y);
				return (1);
			}
			i++;
		}
		j++;
	}
	ft_free_map(map, data->y);
	return (0);
}
