/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:26:31 by torandri          #+#    #+#             */
/*   Updated: 2024/06/05 15:44:26 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_when_quit(t_data *data)
{
	ft_free_map(data->map, data->y);
	mlx_destroy_window(data->vars.mlx, data->vars.mlx_win);
	mlx_loop_end(data->vars.mlx);
	mlx_destroy_display(data->vars.mlx);
	free(data->vars.mlx);
}

int	ft_key_events(int keycode, t_data *data)
{
	int		new_x;
	int		new_y;

	new_x = data->pos_x;
	new_y = data->pos_y;
	if (keycode == XK_ESC)
	{
		ft_free_when_quit(data);
		exit (0);
		return (0);
	}
	else if (keycode == XK_W)
		move_up_player(data);
	else if (keycode == XK_S)
		move_down_player(data);
	else if (keycode == XK_A)
		move_left_player(data);
	else if (keycode == XK_D)
		move_right_player(data);
	return (1);
}

int	ft_mouse_events(t_data *data)
{
	ft_free_when_quit(data);
	exit (0);
	return (0);
}
