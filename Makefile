# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 14:46:14 by dafranco          #+#    #+#              #
#    Updated: 2023/09/19 16:57:33 by dafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_B = cub3D_bonus

MY_SOURCES =	raycasting/draw.c								\
				utils/get_next_valid_line.c						\
				utils/get_texture_path.c						\
				utils/free_structs.c							\
				checker/checker.c								\
				checker/checker_utils.c							\
				checker/checker_texture.c						\
				checker/checker_tab.c							\
				checker/checker_lines_and_columns.c				\
				data/constructors.c								\
				data/get_data.c									\
				data/get_hexa_color.c							\
				data/get_map_utils.c							\
				data/get_map.c									\
				data/get_player.c								\
				data/get_raw_tab.c								\
				data/get_tab.c									\
				data/init_display_datas.c						\
				raycasting/raykst.c								\
				raycasting/calc_ray.c							\
				raycasting/set_colors.c							\

MY_SOURCES_M =	main.c											\
				game/movements.c								\
				game/directions.c								\
			
MY_SOURCES_B =	bonus/main_bonus.c								\
				bonus/movements_bonus.c							\
				bonus/directions_bonus.c						\

MY_OBJECTS = $(MY_SOURCES:%.c=%.o)

MY_OBJECTS_B = $(MY_SOURCES_B:%.c=%.o)

MY_OBJECTS_M = $(MY_SOURCES_M:%.c=%.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g -I.

all : $(NAME)

bonus : $(NAME_B)

$(NAME_B): $(MY_OBJECTS_B) $(MY_OBJECTS)
	make -C libft/
	cmake MLX42 -B MLX42/build && make -C MLX42/build -j4
	$(CC) $(CFLAGS) -L libft -I libft $(MY_OBJECTS_B) $(MY_OBJECTS) libft/libft.a -I/usr/include MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -o $(NAME_B)

$(NAME): $(MY_OBJECTS_M) $(MY_OBJECTS)
	make -C libft/
	cmake MLX42 -B MLX42/build && make -C MLX42/build -j4
	$(CC) $(CFLAGS) -L libft -I libft $(MY_OBJECTS_M) $(MY_OBJECTS) libft/libft.a -I/usr/include MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -o $(NAME)

clean:
	rm -f $(MY_OBJECTS) $(MY_OBJECTS_M)
	rm -f raycasting/$(MY_OBJECTS)
	rm -f utils/$(MY_OBJECTS)
	rm -f data/$(MY_OBJECTS)
	rm -f game/$(MY_OBJECTS_M)
	rm -f checker/$(MY_OBJECTS)
	rm -f bonus/$(MY_OBJECTS_B)
	rm -f bonus/main_bonus.o
	rm -rf MLX42/build
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	rm -rf libft/libft.a

re: fclean all

.PHONY : all bonus clean fclean re
