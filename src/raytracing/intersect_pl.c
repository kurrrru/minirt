/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:20:17 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/16 23:41:04 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

int	intersect_plane(t_object *obj, t_vec origin, t_vec direction,
		double *dist, t_vec *intersection, t_vec *normal)
{
	double denom;
	double t;
	
	denom = dot_product(obj->norm_vector, direction);
	if (fabs(denom) < 1e-6)
		return (0);
	t = dot_product(subtract(obj->center, origin), obj->norm_vector) / denom;
	if (t < 0 || t >= *dist)
		return (0);
	*dist = t;
	*intersection = add(origin, scale(direction, t));
	*normal = normalize(obj->norm_vector);
	return (1);
}