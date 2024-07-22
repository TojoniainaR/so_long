/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:49:30 by torandri          #+#    #+#             */
/*   Updated: 2024/06/05 16:01:44 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_data *data, int new_x, int new_y)
{
	int			j;
	t_data_img	*data_img;

	data->collect = ft_collect_number(data);
	if (data->map[new_y][new_x] == 'E' && data->collect == 0)
	{
		data->map[data->pos_y][data->pos_x] = '0';
		data->map[new_y][new_x] = 'P';
		ft_free_when_quit(data);
		exit (0);
	}
	if (data->map[new_y][new_x] != '1' && data->map[new_y][new_x] != 'E')
	{
		data->map[data->pos_y][data->pos_x] = '0';
		data->map[new_y][new_x] = 'P';
		data->pos_x = new_x;
		data->pos_y = new_y;
		ft_printf("move %d\n", data->move++);
		ft_put_image(data);
	}
}

void	move_up_player(t_data *data)
{
	int		new_x;
	int		new_y;
	void	*image;

	new_x = data->pos_x;
	new_y = data->pos_y - 1;
	ft_move_player(data, new_x, new_y);
	image = mlx_xpm_file_to_image(data->vars.mlx, "./xpm/char_back.xpm", \
	&data->width, &data->height);
	mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, image, \
	data->pos_x * SCALE, data->pos_y * SCALE);
	mlx_destroy_image(data->vars.mlx, image);
}

void	move_down_player(t_data *data)
{
	int		new_x;
	int		new_y;
	void	*image;

	new_x = data->pos_x;
	new_y = data->pos_y + 1;
	ft_move_player(data, new_x, new_y);
	image = mlx_xpm_file_to_image(data->vars.mlx, "./xpm/char_front.xpm", \
	&data->width, &data->height);
	mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, image, \
	data->pos_x * SCALE, data->pos_y * SCALE);
	mlx_destroy_image(data->vars.mlx, image);
}

void	move_left_player(t_data *data)
{
	int		new_x;
	int		new_y;
	void	*image;

	new_x = data->pos_x - 1;
	new_y = data->pos_y;
	ft_move_player(data, new_x, new_y);
	image = mlx_xpm_file_to_image(data->vars.mlx, "./xpm/char_left.xpm", \
	&data->width, &data->height);
	mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, image, \
	data->pos_x * SCALE, data->pos_y * SCALE);
	mlx_destroy_image(data->vars.mlx, image);
}

void	move_right_player(t_data *data)
{
	int		new_x;
	int		new_y;
	void	*image;

	new_x = data->pos_x + 1;
	new_y = data->pos_y;
	ft_move_player(data, new_x, new_y);
	image = mlx_xpm_file_to_image(data->vars.mlx, "./xpm/char_right.xpm", \
	&data->width, &data->height);
	mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, image, \
	data->pos_x * SCALE, data->pos_y * SCALE);
	mlx_destroy_image(data->vars.mlx, image);
}
