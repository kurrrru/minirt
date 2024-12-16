/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:45:39 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/16 00:21:32 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

int	intersect(t_object *obj, t_vec origin, t_vec direction, double *dist,
		t_vec *intersection, t_vec *normal)
{
	if (obj->shape == SPHERE)
	{
		return (intersect_sphere(obj, origin, direction, dist, intersection,
				normal));
	}
	else if (obj->shape == PLANE)
	{
		return (intersect_plane(obj, origin, direction, dist, intersection,
				normal));
	}
	else if (obj->shape == CYLINDER)
	{
		return (intersect_cylinder(obj, origin, direction, dist, intersection,
				normal));
	}
	return (0);
}
