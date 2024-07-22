/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:00:57 by torandri          #+#    #+#             */
/*   Updated: 2024/07/22 17:33:03 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(char **map, t_data *data, int beg_x, int beg_y)
{
	if (beg_x < 0 || beg_x >= data->x || beg_y < 0 || beg_y >= data->y)
		return ;
	if (map[beg_y][beg_x] == '1' || map[beg_y][beg_x] == 'F' \
	|| map[beg_y][beg_x] == 'E')
		return ;
	map[beg_y][beg_x] = 'F';
	fill_map(map, data, beg_x - 1, beg_y);
	fill_map(map, data, beg_x + 1, beg_y);
	fill_map(map, data, beg_x, beg_y - 1);
	fill_map(map, data, beg_x, beg_y + 1);
}

int	ft_check_map_valid(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = ft_tmp_map(&data->x, &data->y, data->file);
	fill_map(map, data, 1, 1);
	j = 0;
	while (j < data->y)
	{
		i = 0;
		while (i < data->x)
		{
			if (map[j][i] == 'P' || map[j][i] == 'C')
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
