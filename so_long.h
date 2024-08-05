/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:52:17 by torandri          #+#    #+#             */
/*   Updated: 2024/08/05 14:08:19 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SCALE 32
# define XK_ESC 65307
# define XK_A 97
# define XK_D 100
# define XK_S 115
# define XK_W 119

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "./gnl/get_next_line_bonus.h"
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}				t_vars;

typedef struct s_check_map
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;
	int	c_count;
}				t_check_map;

typedef struct s_data_img
{
	int		i;
	int		j;
	int		width;
	int		height;
	void	*img;
	void	*img_ext_lup;
	void	*img_ext_ldown;
	void	*img_ext_rup;
	void	*img_ext_rdown;
	void	*img_ext_up;
	void	*img_ext_down;
	void	*img_ext_left;
	void	*img_ext_right;
}				t_data_img;

typedef struct s_data
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			fd;
	int			width;
	int			height;
	int			pos_x;
	int			pos_y;
	int			pos_e_x;
	int			pos_e_y;
	int			move;
	int			collect;
	char		*file;
	char		**map;
	void		*objects[4];
	t_vars		vars;
	t_data_img	data_img;
}				t_data;

typedef struct s_tmp_map
{
	int		i;
	int		fd;
	int		_x;
	int		_y;
	char	*tmp;
	char	**map;
}				t_tmp_map;

int		ft_error(t_data data);
int		ft_check_error(int argc, char *argv[]);
int		take_value_x(int x, int fd);
int		take_value_y(int y, int fd);
int		ft_key_events(int keycode, t_data *data);
int		ft_mouse_events(t_data *data);
int		ft_check_map_error(int x, int y, char *file);
int		ft_check_map_error_other(int x, int y, char *file);
int		ft_collect_number(t_data *data);
int		ft_loop_map(int x, int y, char **map);
int		ft_check_map_valid(t_data *data);
int		surrounded_vertical(int y, char **map);
int		surrounded_horizontal(int x, int y, char **map);
int		ft_strlen_mod(const char *str);
char	**ft_tmp_map(int *x, int *y, char *file);
void	ft_free_when_quit(t_data *data);
void	ft_free_map(char **map, int line);
void	move_up_player(t_data *data);
void	move_down_player(t_data *data);
void	move_left_player(t_data *data);
void	move_right_player(t_data *data);
void	ft_get_pos_player(t_data *data);
void	ft_get_pos_exit(t_data *data);
void	ft_initiate_data(t_data *data);
void	ft_initiate_check(t_check_map *check);
void	ft_map_size(int *x, int *y, char *file);
void	ft_init_map(void *mlx, void *mlx_win, int x, int y);
void	ft_put_image(t_data *data);
void	ft_move_player(t_data *data, int new_x, int new_y);

#endif