/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:56:55 by torandri          #+#    #+#             */
/*   Updated: 2024/08/05 16:39:34 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	surrounded_vertical(int y, char **map)
{
	size_t	i;

	i = 0;
	while (map[0][i] != '\0' && map[y - 1][i] != '\0')
	{
		if (map[0][i] != '1' || map[y - 1][i] != '1')
		{
			ft_printf("Error\nInvalid map, must be surrounded by 1\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	surrounded_horizontal(int x, int y, char **map)
{
	int	j;

	j = 0;
	while (j < y && *map[j] != '\0')
	{
		if (ft_strlen_mod(map[j]) != x)
		{
			ft_printf("Error\nInvalid map, must be rectangle\n");
			return (1);
		}
		if (map[j][0] != '1' || map[j][x - 1] != '1')
		{
			ft_printf("Error\nInvalid map, must be surrounded by 1\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_condition(t_check_map check)
{
	if (check.p_count == 0 || check.e_count == 0 || check.c_count == 0)
	{
		ft_printf("Error\nInvalid map !! (Check P or E or C)\n");
		return (1);
	}
	if (check.e_count > 1 || check.p_count > 1)
	{
		ft_printf("Error\nInvalid map !! (Check P or E)\n");
		return (1);
	}
	return (0);
}

int	inside_map(int x, int y, char **map)
{
	t_check_map	check;

	ft_initiate_check(&check);
	while (check.j < y && map[check.j][check.i] != '\0')
	{
		check.i = 1;
		while (check.i < x)
		{
			if (map[check.j][check.i] == 'P')
				check.p_count++;
			if (map[check.j][check.i] == 'E')
				check.e_count++;
			if (map[check.j][check.i] == 'C')
				check.c_count++;
			check.i++;
		}
		check.j++;
	}
	if (ft_condition(check) == 1)
		return (1);
	return (0);
}

int	ft_check_map_error(int x, int y, char *file)
{
	char		**map;

	map = ft_tmp_map(&x, &y, file);
	if (!map)
	{
		ft_free_map(map, y);
		return (1);
	}
	if (ft_check_map_error_other(x, y, file) == 1)
	{
		ft_free_map(map, y);
		return (1);
	}
	if (ft_loop_map(x, y, map) == 1)
	{
		ft_free_map(map, y);
		return (1);
	}
	if (inside_map(x, y, map) == 1)
	{
		ft_free_map(map, y);
		return (1);
	}
	ft_free_map(map, y);
	return (0);
}
