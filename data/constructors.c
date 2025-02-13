/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:48:15 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/19 13:26:37 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

t_map	*map_constructor(void)
{
	t_map	*map;

	map = calloc2(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->tab = NULL;
	map->width = 0;
	map->height = 0;
	map->pos_x = 0.0;
	map->pos_y = 0.0;
	map->dir_x = 0.0;
	map->dir_y = 0.0;
	map->plane_x = 0.0;
	map->plane_y = 0.0;
	return (map);
}

static t_player	*player_init_pos(t_player *player)
{
	player->start = 0;
	player->map_x = 0;
	player->map_y = 0;
	player->step_x = 0;
	player->step_y = 0;
	player->step = 0;
	return (player);
}

t_player	*player_constructor(void)
{
	t_player	*player;

	player = calloc2(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->tex_x = 0;
	player->tex_y = 0;
	player->tex_pos = 0.0;
	player->camera_x = 0.0;
	player->ray_dir_x = 0.0;
	player->ray_dir_y = 0.0;
	player->side_dist_x = 0.0;
	player->side_dist_y = 0.0;
	player->delta_dist_x = 0.0;
	player->delta_dist_y = 0.0;
	player->perp_wall_dist = 0.0;
	player->side = 0;
	player->line_height = 0;
	player->wall_x = 0;
	player->draw_start = 0;
	player->draw_end = 0;
	player = player_init_pos(player);
	return (player);
}

t_data	*data_constructor(void)
{
	t_data	*data;

	data = calloc2(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = NULL;
	data->title = NULL;
	data->map = NULL;
	data->player = NULL;
	data->texture = NULL;
	data->texture_n = NULL;
	data->texture_s = NULL;
	data->texture_e = NULL;
	data->texture_w = NULL;
	data->r = 0;
	data->g = 0;
	data->b = 0;
	return (data);
}
