/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:24:01 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/25 18:36:33 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static void	set_player_dir(t_data *data)
{
	if (data->player->start == 'S')
	{
		data->map->dir_x = 1.0;
		data->map->plane_y = -0.66;
	}
	if (data->player->start == 'N')
	{
		data->map->dir_x = -1.0;
		data->map->plane_y = 0.66;
	}
	if (data->player->start == 'W')
	{
		data->map->dir_y = 1.0;
		data->map->plane_x = 0.66;
	}
	if (data->player->start == 'E')
	{
		data->map->dir_y = -1.0;
		data->map->plane_x = -0.66;
	}
}

static void	set_player_pos(t_data *data, char **tab)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == 'N' || tab[y][x] == 'S'
			|| tab[y][x] == 'E' || tab[y][x] == 'W')
			{
				data->map->pos_y = (double)x + 0.5;
				data->map->pos_x = (double)y + 0.5;
				data->player->start = tab[y][x];
			}
			x++;
		}
		y++;
		x = 0;
	}
	set_player_dir(data);
}

t_player	*get_player(t_data *data, char **tab)
{
	t_player	*player;

	player = player_constructor();
	if (!player)
		return (NULL);
	data->player = player;
	set_player_pos(data, tab);
	return (player);
}
