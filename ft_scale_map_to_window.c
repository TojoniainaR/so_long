/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_map_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:03:53 by torandri          #+#    #+#             */
/*   Updated: 2024/07/01 17:03:07 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	take_value_x(int x, int fd)
{
	char	*length_x;

	length_x = get_next_line(fd);
	x = ft_strlen(length_x);
	free(length_x);
	if (x <= 0)
		return (0);
	if (x == 1)
		return (1);
	x -= 1;
	return (x);
}

int	take_value_y(int y, int fd)
{
	char	*length_y;

	y = 0;
	length_y = "";
	while (length_y)
	{
		length_y = get_next_line(fd);
		free(length_y);
		y++;
	}
	if (y == 1)
		return (1);
	y++;
	return (y);
}

void	ft_map_size(int *x, int *y, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 2)
	{
		ft_printf("Error\nMap not found\n");
		free(file);
		exit (0);
	}
	else if ((take_value_x(*x, fd) == 1) && (take_value_y(*y, fd) == 1))
	{
		ft_printf("Invalid size of map\n");
		return ;
	}
	else
	{
		*x = take_value_x(*x, fd);
		*y = take_value_y(*y, fd);
	}
	close(fd);
}
