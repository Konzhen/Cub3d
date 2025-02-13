/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:13:18 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/19 16:25:00 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libcub.h"

void	rota_right(t_data *data, t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0;
	old_plane_x = 0;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
	{
		old_dir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(-0.1) - map->dir_y * sin(-0.1);
		map->dir_y = old_dir_x * sin(-0.1) + map->dir_y * cos(-0.1);
		old_plane_x = map->plane_x;
		map->plane_x = map->plane_x * cos(-0.1) - map->plane_y * sin(-0.1);
		map->plane_y = old_plane_x * sin(-0.1) + map->plane_y * cos(-0.1);
	}
}

void	rota_left(t_data *data, t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0;
	old_plane_x = 0;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
	{
		old_dir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(0.1) - map->dir_y * sin(0.1);
		map->dir_y = old_dir_x * sin(0.1) + map->dir_y * cos(0.1);
		old_plane_x = map->plane_x;
		map->plane_x = map->plane_x * cos(0.1) - map->plane_y * sin(0.1);
		map->plane_y = old_plane_x * sin(0.1) + map->plane_y * cos(0.1);
	}
}
