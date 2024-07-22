# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torandri <torandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 08:30:54 by torandri          #+#    #+#              #
#    Updated: 2024/07/15 16:02:08 by torandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

MLX = -Lminilibx-linux -lmlx -lX11 -lXext

LIBFT = -Llibft -lft

PRINTF = -Lprintf -lftprintf

GNL = -Lgnl -lgnl

RM = rm -f

HEADER = ./minilibx-linux/mlx.h

LIBC = ar -rcs

SRCS = main.c ft_check_map_error.c ft_scale_map_to_window.c ft_init_map.c ft_check_error.c ft_events.c ft_move.c so_long_utils.c ft_put_image.c ft_check_map_valid.c

OBJS = main.o ft_check_map_error.o ft_scale_map_to_window.o ft_init_map.o ft_check_error.o ft_events.o ft_move.o so_long_utils.o ft_put_image.o ft_check_map_valid.o ############### $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	make -C ./printf
	make -C ./gnl
	$(CC) $(FLAGS) -g $(SRCS) $(MLX) $(LIBFT) $(PRINTF) $(GNL) -o $@ $<

.c.o :
	$(CC) -o $@ -c $^

clean :
	@$(RM) *.o

fclean : clean
	@$(RM) $(NAME)

re : fclean all
