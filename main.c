/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:23:36 by torandri          #+#    #+#             */
/*   Updated: 2024/07/22 16:09:24 by torandri         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_initiate_data(&data);
	if (ft_check_error(argc, argv) == 1)
		return (1);
	data.file = ft_strjoin("./map/", argv[1]);
	ft_map_size(&data.x, &data.y, data.file);
	if (ft_error(data) == 1)
		return (1);
	data.vars.mlx = mlx_init();
	data.vars.mlx_win = mlx_new_window(data.vars.mlx, \
	data.x * SCALE, data.y * SCALE, "so_long");
	ft_get_pos_player(&data);
	ft_put_image(&data);
	free(data.file);
	mlx_key_hook(data.vars.mlx_win, ft_key_events, &data);
	mlx_hook(data.vars.mlx_win, 17, 1L << 17, \
	ft_mouse_events, &data);
	mlx_loop(data.vars.mlx);
	return (0);
}
