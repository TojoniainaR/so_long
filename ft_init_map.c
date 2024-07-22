/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:11:19 by torandri          #+#    #+#             */
/*   Updated: 2024/06/05 15:06:58 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_ext_corner(void *mlx, void *mlx_win, int x, int y)
{
	t_data_img	data_img;

	data_img.img_ext_lup = mlx_xpm_file_to_image(mlx, "./xpm/ext_lup.xpm", \
	&data_img.width, &data_img.height);
	mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_lup, \
	0 * SCALE, 0 * SCALE);
	mlx_destroy_image(mlx, data_img.img_ext_lup);
	data_img.img_ext_ldown = mlx_xpm_file_to_image(mlx, "./xpm/ext_ldown.xpm", \
	&data_img.width, &data_img.height);
	mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_ldown, \
	0 * SCALE, (y - 1) * SCALE);
	mlx_destroy_image(mlx, data_img.img_ext_ldown);
	data_img.img_ext_rup = mlx_xpm_file_to_image(mlx, "./xpm/ext_rup.xpm", \
	&data_img.width, &data_img.height);
	mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_rup, \
	(x - 1) * SCALE, 0 * SCALE);
	mlx_destroy_image(mlx, data_img.img_ext_rup);
	data_img.img_ext_rdown = mlx_xpm_file_to_image(mlx, "./xpm/ext_rdown.xpm", \
	&data_img.width, &data_img.height);
	mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_rdown, \
	(x - 1) * SCALE, (y - 1) * SCALE);
	mlx_destroy_image(mlx, data_img.img_ext_rdown);
}

void	ft_put_ext_h(void *mlx, void *mlx_win, int x, int y)
{
	t_data_img	data_img;

	data_img.img_ext_up = mlx_xpm_file_to_image(mlx, "./xpm/ext_up.xpm", \
	&data_img.width, &data_img.height);
	data_img.i = 1;
	while (data_img.i * SCALE < (x - 1) * SCALE)
	{
		mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_up, \
		data_img.i * SCALE, 0 * SCALE);
		data_img.i++;
	}
	mlx_destroy_image(mlx, data_img.img_ext_up);
	data_img.img_ext_down = mlx_xpm_file_to_image(mlx, "./xpm/ext_down.xpm", \
	&data_img.width, &data_img.height);
	data_img.i = 1;
	while (data_img.i * SCALE < (x - 1) * SCALE)
	{
		mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_down, \
		data_img.i * SCALE, (y - 1) * SCALE);
		data_img.i++;
	}
	mlx_destroy_image(mlx, data_img.img_ext_down);
}

void	ft_put_ext_v(void *mlx, void *mlx_win, int x, int y)
{
	t_data_img	data_img;

	data_img.img_ext_left = mlx_xpm_file_to_image(mlx, "./xpm/ext_left.xpm", \
	&data_img.width, &data_img.height);
	data_img.j = 1;
	while (data_img.j * SCALE < (y - 1) * SCALE)
	{
		mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_left, \
		0 * SCALE, data_img.j * SCALE);
		data_img.j++;
	}
	mlx_destroy_image(mlx, data_img.img_ext_left);
	data_img.img_ext_right = mlx_xpm_file_to_image(mlx, "./xpm/ext_right.xpm", \
	&data_img.width, &data_img.height);
	data_img.j = 1;
	while (data_img.j * SCALE < (y - 1) * SCALE)
	{
		mlx_put_image_to_window(mlx, mlx_win, data_img.img_ext_right, \
		(x - 1) * SCALE, data_img.j * SCALE);
		data_img.j++;
	}
	mlx_destroy_image(mlx, data_img.img_ext_right);
}

void	ft_put_inside_map(void *mlx, void *mlx_win, int x, int y)
{
	t_data_img	data_img;

	data_img.i = 1;
	data_img.j = 1;
	data_img.img = mlx_xpm_file_to_image(mlx, "./xpm/item_0.xpm", \
	&data_img.width, &data_img.height);
	while (data_img.i < x - 1)
	{
		data_img.j = 1;
		while (data_img.j < y - 2)
		{
			mlx_put_image_to_window(mlx, mlx_win, data_img.img, \
			data_img.i * SCALE, data_img.j * SCALE);
			data_img.j++;
		}
		mlx_put_image_to_window(mlx, mlx_win, data_img.img, \
		data_img.i * SCALE, data_img.j * SCALE);
		data_img.i++;
	}
	mlx_destroy_image(mlx, data_img.img);
}

void	ft_init_map(void *mlx, void *mlx_win, int x, int y)
{
	ft_put_ext_corner(mlx, mlx_win, x, y);
	ft_put_ext_h(mlx, mlx_win, x, y);
	ft_put_ext_v(mlx, mlx_win, x, y);
	ft_put_inside_map(mlx, mlx_win, x, y);
}
