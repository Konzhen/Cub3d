/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display_datas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:39:29 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/19 13:28:35 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libcub.h"

void	init_view_side(t_data *data)
{
	if (data->player->ray_dir_x == 0.0)
		data->player->delta_dist_x = 9999;
	else
		data->player->delta_dist_x = fabs(1.0 / data->player->ray_dir_x);
	if (data->player->ray_dir_y == 0.0)
		data->player->delta_dist_y = 9999;
	else
		data->player->delta_dist_y = fabs(1.0 / data->player->ray_dir_y);
}

void	init_view_distance(t_data *data, t_player *player)
{
	init_view_side(data);
	if (player->ray_dir_x < 0.0)
	{
		player->step_x = -1;
		player->side_dist_x = ((double)(data->map->pos_x - \
		(double)player->map_x)) * player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = ((double)player->map_x + 1.0 - data->map->pos_x) \
			* player->delta_dist_x;
	}
	if (player->ray_dir_y < 0.0)
	{
		player->step_y = -1;
		player->side_dist_y = (data->map->pos_y - (double)player->map_y) \
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = ((double)player->map_y + 1.0 - data->map->pos_y) \
			* player->delta_dist_y;
	}
}

void	init_player_view(t_data *data, t_player *player)
{
	player->camera_x = 2.0 * (double)player->x / (double)WIDTH - 1.0;
	player->ray_dir_x = data->map->dir_x + data->map->plane_x * \
		player->camera_x;
	player->ray_dir_y = data->map->dir_y + data->map->plane_y * \
		player->camera_x;
	player->map_x = (int)data->map->pos_x;
	player->map_y = (int)data->map->pos_y;
}

void	init_perp(t_player *player)
{
	if (player->side == 0)
		player->perp_wall_dist = (player->side_dist_x - player->delta_dist_x);
	else
		player->perp_wall_dist = (player->side_dist_y - player->delta_dist_y);
}
