/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:25:14 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/19 13:36:52 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

void	raycasting_loop(t_data *data, t_player *player)
{
	while (player->x < WIDTH)
	{
		init_player_view(data, player);
		init_view_distance(data, player);
		shoot_ray(data);
		init_perp(player);
		player->line_height = (int)((double)HEIGHT / player->perp_wall_dist);
		rescale_pixel_size(data);
		if (player->side == 0)
			player->wall_x = data->map->pos_y + \
				player->perp_wall_dist * player->ray_dir_y;
		else
			player->wall_x = data->map->pos_x + \
				player->perp_wall_dist * player->ray_dir_x;
		player->wall_x -= floor(player->wall_x);
		dir_texture(data);
		player->tex_x = (int)(player->wall_x * data->texture->width);
		if (player->side == 0 && player->ray_dir_x > 0.0)
			player->tex_x = data->texture->width - player->tex_x - 1;
		if (player->side == 1 && player->ray_dir_y < 0.0)
			player->tex_x = data->texture->width - player->tex_x - 1;
		draw_all_elements(data, player);
		player->x++;
	}
}

void	raycasting(t_data *data)
{
	t_player	*player;

	player = data->player;
	data->player->tex_width = 64;
	data->player->tex_height = 64;
	data->player->x = 0;
	data->player->y = 0;
	raycasting_loop(data, player);
	mlx_image_to_window(data->mlx_ptr, data->render, 0, 0);
}
