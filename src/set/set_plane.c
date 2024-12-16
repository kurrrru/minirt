/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:53:56 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 01:01:20 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

int	set_plane(t_data *data, char **params)
{
	t_object	*plane;

	if (array_len(params) != 3)
		return (-1);
	plane = xmalloc(sizeof(t_object));
	plane->shape = PLANE;
	plane->center = parse_vec(params[0]);
	plane->norm_vector = parse_vec(params[1]);
	plane->color = parse_color(params[2]);
	ft_lstadd_back(&(data->objects), xlstnew(plane));
	return (0);
}
