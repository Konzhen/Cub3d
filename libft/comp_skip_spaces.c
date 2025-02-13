/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_skip_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:20:52 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/05 17:24:11 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_spaces(const char *line, int *i)
{
	int	j;
	int	spc;

	j = 0;
	spc = 0;
	if (!i)
		i = &j;
	if (!line || !line[*i])
		return (-2);
	while ((line[*i] >= 7 && line[*i] <= 13) || line[*i] == ' ')
	{
		(*i)++;
		spc++;
	}
	if (!line[*i])
		return (-1);
	return (spc);
}
