/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:13:38 by torandri          #+#    #+#             */
/*   Updated: 2024/08/05 13:26:11 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_put_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->vars.mlx, data->objects[i]);
		i++;
	}
}

void	ft_exit(t_data *data, t_data_img *data_img)
{
	if (data->map[data->pos_e_y][data->pos_e_x] != 'E' \
	&& data->map[data->pos_e_y][data->pos_e_x] != 'P')
		data->map[data->pos_e_y][data->pos_e_x] = 'E';
	data_img->i = 1;
	data_img->j = 1;
}

void	ft_image(t_data *data)
{
	t_data_img	data_img;

	ft_exit(data, &data_img);
	while (data_img.j < data->y - 1 && \
	data->map[data_img.j][data_img.i] != '\0')
	{
		data_img.i = 1;
		while (data_img.i < data->x - 1)
		{
			if (data->map[data_img.j][data_img.i] == '1')
				mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, \
				data->objects[0], data_img.i * SCALE, data_img.j * SCALE);
			if (data->map[data_img.j][data_img.i] == 'P')
				mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, \
				data->objects[1], data_img.i * SCALE, data_img.j * SCALE);
			if (data->map[data_img.j][data_img.i] == 'C')
				mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, \
				data->objects[2], data_img.i * SCALE, data_img.j * SCALE);
			if (data->map[data_img.j][data_img.i] == 'E')
				mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, \
				data->objects[3], data_img.i * SCALE, data_img.j * SCALE);
			data_img.i++;
		}
		data_img.j++;
	}
}

void	ft_put_image(t_data *data)
{
	t_data_img	data_img;

	data->objects[0] = mlx_xpm_file_to_image(data->vars.mlx, \
	"./xpm/item_1.xpm", &data_img.width, &data_img.height);
	data->objects[1] = mlx_xpm_file_to_image(data->vars.mlx, \
	"./xpm/char_front.xpm", &data_img.width, &data_img.height);
	data->objects[2] = mlx_xpm_file_to_image(data->vars.mlx, \
	"./xpm/item_C.xpm", &data_img.width, &data_img.height);
	data->objects[3] = mlx_xpm_file_to_image(data->vars.mlx, \
	"./xpm/item_E.xpm", &data_img.width, &data_img.height);
	ft_init_map(data->vars.mlx, data->vars.mlx_win, data->x, data->y);
	ft_image(data);
	ft_free_put_img(data);
}
