/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:34:49 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/05 21:38:04 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libcub.h"

int	get_rgba(t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = data->r;
	g = data->g;
	b = data->b;
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	set_rgb(t_data *data)
{
	int	pixel;

	pixel = (data->texture->width * data->player->tex_y + data->player->tex_x) \
		* data->texture->bytes_per_pixel;
	data->r = data->texture->pixels[pixel];
	data->g = data->texture->pixels[pixel + 1];
	data->b = data->texture->pixels[pixel + 2];
}
