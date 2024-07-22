/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:40:34 by torandri          #+#    #+#             */
/*   Updated: 2024/07/01 13:40:38 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_mod(const char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count--;
		count++;
		i++;
	}
	return (count);
}

char	**ft_tmp_map(int *x, int *y, char *file)
{
	t_tmp_map	tmp_map;

	tmp_map.i = 0;
	tmp_map._x = *x;
	tmp_map._y = *y;
	tmp_map.fd = open(file, O_RDONLY);
	tmp_map.map = (char **)malloc(tmp_map._y * sizeof(char *));
	if (tmp_map.fd <= 0 || !file || !tmp_map.map)
		return (NULL);
	while (tmp_map.i <= tmp_map._y)
	{
		tmp_map.tmp = get_next_line(tmp_map.fd);
		if (!tmp_map.tmp)
			break ;
		tmp_map.map[tmp_map.i] = ft_strdup(tmp_map.tmp);
		free(tmp_map.tmp);
		tmp_map.i++;
	}
	close (tmp_map.fd);
	return (tmp_map.map);
}

void	ft_get_pos_player(t_data *data)
{
	int	i;
	int	j;
	int	found;

	j = 0;
	found = 0;
	data->map = ft_tmp_map(&data->x, &data->y, data->file);
	while (j < data->y && found != 1)
	{
		i = 0;
		while (i < data->x)
		{
			if (data->map[j][i] == 'P')
			{
				found = 1;
				break ;
			}
			i++;
		}
		j++;
	}
	data->pos_x = i;
	data->pos_y = j - 1;
}

int	ft_collect_number(t_data *data)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	j = 0;
	number = 0;
	while (j < data->y)
	{
		i = 0;
		while (i < data->x)
		{
			if (data->map[j][i] == 'C')
				number++;
			i++;
		}
		j++;
	}
	return (number);
}
