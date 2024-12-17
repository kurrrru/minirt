/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:45:39 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 00:58:37 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

int	intersect(t_vec origin, t_vec direction, t_closest_obj *find_obj)
{
	if (find_obj->closest_obj->shape == SPHERE)
		return (intersect_sphere(origin, direction, find_obj));
	else if (find_obj->closest_obj->shape == PLANE)
		return (intersect_plane(origin, direction, find_obj));
	else if (find_obj->closest_obj->shape == CYLINDER)
		return (intersect_cylinder(origin, direction, find_obj));
	return (0);
}
