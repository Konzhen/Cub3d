/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 05:02:45 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/19 15:30:30 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->tab)
		free_tab((void **)map->tab, 0);
	if (map->no)
	{
		free(map->no);
		map->no = NULL;
	}
	if (map->so)
	{
		free(map->so);
		map->so = NULL;
	}
	if (map->we)
	{
		free(map->we);
		map->we = NULL;
	}
	if (map->ea)
	{
		free(map->ea);
	}
}

void	free_player(t_player *player)
{
	if (!player)
		return ;
	if (player)
		free(player);
}

void	free_data(t_data *data)
{
	if (data->title)
		free(data->title);
	if (data->player)
		free_player(data->player);
	if (data->map)
		free(data->map);
	free(data);
}

void	free_all(t_data *data)
{
	t_map		*map;

	map = (t_map *)data->map;
	free_map(map);
	free_data(data);
	return ;
}

void	shut_down(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_terminate(data->mlx_ptr);
	free_all(data);
	exit(0);
}
