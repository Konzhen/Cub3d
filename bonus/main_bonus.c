/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/09/19 16:47:54 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub_bonus.h"

int	main(int argc, char **argv)
{
	int				fd;
	t_data			*data;

	if (check_argc(argc, 2, 2))
		return (1);
	fd = checker(argv[1]);
	if (fd == -1)
		return (1);
	data = get_data(fd, argv[1]);
	if (!data)
		return (1);
	load_image(data);
	raycasting(data);
	mlx_loop_hook(data->mlx_ptr, movements_bonus, data);
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
	shut_down(&data);
	return (EXIT_SUCCESS);
}
