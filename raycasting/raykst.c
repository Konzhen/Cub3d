/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raykst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:34:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/08 22:59:34 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libcub.h"

void	rescale_pixel_size(t_data *data)
{
	data->player->draw_start = -data->player->line_height / 2 + HEIGHT / 2;
	if (data->player->draw_start < 0)
		data->player->draw_start = 0;
	data->player->draw_end = data->player->line_height / 2 + HEIGHT / 2;
	if (data->player->draw_end >= HEIGHT)
		data->player->draw_end = HEIGHT - 1;
}

void	shoot_ray(t_data *data)
{
	data->player->hit = 0;
	while (data->player->hit == 0)
	{
		if (data->player->side_dist_x < data->player->side_dist_y)
		{
			data->player->side_dist_x += data->player->delta_dist_x;
			data->player->map_x += data->player->step_x;
			data->player->side = 0;
		}
		else
		{
			data->player->side_dist_y += data->player->delta_dist_y;
			data->player->map_y += data->player->step_y;
			data->player->side = 1;
		}
		if (data->map->tab[data->player->map_x][data->player->map_y] == '1')
			data->player->hit = 1;
	}
}
