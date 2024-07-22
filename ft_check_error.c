/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:39:43 by tojoniaina        #+#    #+#             */
/*   Updated: 2024/07/22 15:16:08 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initiate_data(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->move = 1;
	data->file = NULL;
}

void	ft_initiate_check(t_check_map *check)
{
	check->i = 1;
	check->j = 1;
	check->p_count = 0;
	check->e_count = 0;
	check->c_count = 0;
}

int	ft_loop_map(int x, int y, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'P' \
			&& map[j][i] != 'E' && map[j][i] != 'C')
			{
				ft_printf(\
				"Error\nThe map must only contain 1, 0, P, C and E\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_check_error(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		ft_printf("Error\nArgument problem\n");
		return (1);
	}
	i = 0;
	while (argv[1][i] != '.')
		i++;
	if (argv[1][i + 4] != '\0')
	{
		ft_printf("Error\nNot the right input, might be <map_name.ber>\n");
		return (1);
	}
	if (!ft_strnstr(argv[1], ".ber\0", ft_strlen(argv[1])) || argv[1][0] == '.')
	{
		ft_printf("Error\nNot the right input, might be <map_name.ber>\n");
		return (1);
	}
}

int	ft_check_map_error_other(int x, int y, char *file)
{
	char		**map;
	t_data		data;

	map = ft_tmp_map(&x, &y, file);
	if (!map)
	{
		ft_free_map(map, y);
		return (1);
	}
	else if (surrounded_vertical(y, map) == 1)
	{
		ft_free_map(map, y);
		return (1);
	}
	else if (surrounded_horizontal(x, y, map) == 1)
	{
		ft_free_map(map, y);
		return (1);
	}
}
