/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:20:57 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/16 23:40:59 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static int check_intersect(double *t1, double *t2, t_vec origin, t_vec direction, t_object *obj);

int	intersect_sphere(t_object *obj, t_vec origin, t_vec direction,
		double *dist, t_vec *intersection, t_vec *normal)
{
	double	t1;
	double	t2;

	if(check_intersect(&t1, &t2, origin, direction, obj) == 0)
		return (0);
	if (t1 > 1e-6 && t1 < *dist)
		*dist = t1;
	else if (t2 > 1e-6 && t2 < *dist)
		*dist = t2;
	else
		return (0);
	*intersection = add(origin, scale(direction, *dist));
	*normal = normalize(subtract(*intersection, obj->center));
	return (1);
}

static int check_intersect(double *t1, double *t2, t_vec origin, t_vec direction, t_object *obj)
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
	*t1 = (-b - sqrt(discriminant)) / (2 * a);
	*t2 = (-b + sqrt(discriminant)) / (2 * a);
	return (1);
}
