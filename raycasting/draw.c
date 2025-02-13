/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/19 16:26:15 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	pixel_ceiling(t_data *data)
{
	uint32_t	ceiling;

	ceiling = get_color_c(0, 0, 0, 1);
	while (data->player->y < data->player->draw_start)
	{
		mlx_put_pixel(data->render, data->player->x, data->player->y, ceiling);
		data->player->y++;
	}
}

void	pixel_floor(t_data *data)
{
	uint32_t	floor;

	floor = get_color_f(0, 0, 0, 1);
	while (data->player->y < HEIGHT)
	{
		mlx_put_pixel(data->render, data->player->x, data->player->y, floor);
		data->player->y++;
	}
}

void	draw_all_elements(t_data *data, t_player *player)
{
	int	color;

	color = 0;
	data->r = 0;
	data->g = 0;
	data->b = 0;
	player->y = 0;
	pixel_ceiling(data);
	player->step = 1.0 * (double)player->tex_height / \
		(double)player->line_height;
	player->tex_pos = ((double)player->draw_start - (double)HEIGHT \
			/ 2.0 + (double)player->line_height / 2.0) * player->step;
	while (player->y < player->draw_end)
	{
		player->tex_y = (int)player->tex_pos & (player->tex_height - 1);
		player->tex_pos += player->step;
		set_rgb(data);
		color = get_rgba(data);
		mlx_put_pixel(data->render, player->x, player->y, color);
		data->player->y++;
	}
	pixel_floor(data);
}
