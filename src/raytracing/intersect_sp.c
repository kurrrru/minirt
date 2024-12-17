/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:20:57 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 17:46:33 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static int	check_intersect(double *t, t_vec origin, t_vec direction,
				t_object *obj);

int	intersect_sphere(t_vec origin, t_vec direction, t_closest_obj *find_obj)
{
	double	t;

	if (check_intersect(&t, origin, direction, find_obj->closest_obj) == 0)
		return (0);
	if (t > 1e-6 && t < find_obj->min_dist)
		find_obj->min_dist = t;
	else
		return (0);
	find_obj->intersection_point = add(origin, scale(direction,
				find_obj->min_dist));
	find_obj->normal = normalize(subtract(find_obj->intersection_point,
				find_obj->closest_obj->center));
	return (1);
}

static int	check_intersect(double *t, t_vec origin, t_vec direction,
		t_object *obj)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = subtract(origin, obj->center);
	a = dot_product(direction, direction);
	b = 2.0 * dot_product(oc, direction);
	c = dot_product(oc, oc) - obj->radius * obj->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	*t = fmin((-b - sqrt(discriminant)) / (2 * a), (-b + sqrt(discriminant))
			/ (2 * a));
	return (1);
}
