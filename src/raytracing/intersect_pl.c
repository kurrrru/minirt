/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:20:17 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 01:00:48 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

int	intersect_plane(t_vec origin, t_vec direction, t_closest_obj *find_obj)
{
	double	denom;
	double	t;

	denom = dot_product(find_obj->closest_obj->norm_vector, direction);
	if (fabs(denom) < 1e-6)
		return (0);
	t = dot_product(subtract(find_obj->closest_obj->center, origin),
			find_obj->closest_obj->norm_vector) / denom;
	if (t < 0 || t >= find_obj->min_dist)
		return (0);
	find_obj->min_dist = t;
	find_obj->intersection_point = add(origin, scale(direction, t));
	find_obj->normal = normalize(find_obj->closest_obj->norm_vector);
	return (1);
}
