/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:47:19 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/26 23:15:40 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub_bonus.h"

static void	key_up(t_data *data, t_map *map)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
	{
		if (map->tab[(int)(map->pos_x + map->dir_x)][(int)map->pos_y] != '1')
			map->pos_x += map->dir_x * 0.2;
		if (map->tab[(int)map->pos_x][(int)(map->pos_y + map->dir_y)] != '1')
			map->pos_y += map->dir_y * 0.2;
	}
}

static void	key_down(t_data *data, t_map *map)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
	{
		if (map->tab[(int)(map->pos_x - map->dir_x)][(int)map->pos_y] != '1')
			map->pos_x -= map->dir_x * 0.2;
		if (map->tab[(int)map->pos_x][(int)(map->pos_y - map->dir_y)] != '1')
			map->pos_y -= map->dir_y * 0.2;
	}
}

static void	key_right(t_data *data, t_map *map)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
	{
		if (map->tab[(int)(map->pos_x + map->dir_y)][(int)(map->pos_y)] \
				!= '1')
			map->pos_x += map->dir_y * 0.1;
		if (map->tab[(int)map->pos_x][(int)(map->pos_y + (-map->dir_x))]
				!= '1')
			map->pos_y += (-map->dir_x) * 0.1;
	}
}

static void	key_left(t_data *data, t_map *map)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
	{
		if (map->tab[(int)(map->pos_x + (-map->dir_y))][(int)map->pos_y] \
				!= '1')
			map->pos_x += (-map->dir_y) * 0.1;
		if (map->tab[(int)map->pos_x][(int)(map->pos_y + map->dir_x)] \
				!= '1')
			map->pos_y += map->dir_x * 0.1;
	}
}

void	movements_bonus(void *param)
{
	t_data	*data;
	t_map	*map;

	data = (t_data *)param;
	map = data->map;
	mlx_set_cursor_mode(data->mlx_ptr, MLX_MOUSE_HIDDEN);
	key_up(data, map);
	key_down(data, map);
	key_left(data, map);
	key_right(data, map);
	rota_right(data, map);
	rota_left(data, map);
	mouse_rota_right(data, map);
	mouse_rota_left(data, map);
	spritize(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
	{
		shut_down(data);
	}
	mlx_close_hook(data->mlx_ptr, shut_down, param);
	raycasting(data);
}
