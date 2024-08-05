# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torandri <torandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 08:30:54 by torandri          #+#    #+#              #
#    Updated: 2024/07/31 10:51:23 by torandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

MLX = -Lminilibx-linux -lmlx -lX11 -lXext

LIBFT = -Llibft -lft

PRINTF = -Lprintf -lftprintf

GNL = -Lgnl -lgnl

RM = rm -f

HEADER = ./so_long.h

SRCS = ft_check_map_error.c ft_scale_map_to_window.c ft_init_map.c ft_check_error.c ft_events.c ft_move.c so_long_utils.c ft_put_image.c ft_check_map_valid.c main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft
	@make -C ./printf
	@make -C ./gnl
	$(CC) $(CFLAGS) $(SRCS) $(MLX) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)

clean :
	@make clean -C ./libft
	@make clean -C ./printf
	@make clean -C ./gnl
	@$(RM) $(OBJS)

fclean : clean
	@make fclean -C ./libft
	@make fclean -C ./printf
	@make fclean -C ./gnl
	@$(RM) $(NAME)

re : fclean all
	@make fclean all -C ./libft
	@make fclean all -C ./printf
	@make fclean all -C ./gnl
