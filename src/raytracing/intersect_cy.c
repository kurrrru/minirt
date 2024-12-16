/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:20:54 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/16 23:40:42 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static int check_intersect(double *t1, double *t2, t_object *obj, t_vec origin, t_vec direction, t_vec *axis);

int	intersect_cylinder(t_object *obj, t_vec origin, t_vec direction,
		double *dist, t_vec *intersection, t_vec *normal)
{	
	double	t1;
	double	t2;
	t_vec	temp_normal;
	t_vec	axis;

	if(check_intersect(&t1, &t2, obj, origin, direction, &axis) == 0)
		return (0);
	if (t1 > 0 && t1 < *dist)
		*dist = t1;
	else if (t2 > 0 && t2 < *dist)
		*dist = t2;
	else
		return (0);
	*intersection = add(origin, scale(direction, *dist));
	temp_normal = subtract(*intersection, obj->center);
	*normal = normalize(subtract(temp_normal, scale(axis,
					dot_product(temp_normal, axis))));
	return (1);
}

static int check_intersect(double *t1, double *t2, t_object *obj, t_vec origin, t_vec direction, t_vec *axis)
{
	t_vec	oc;
	t_vec	d_proj;
	t_vec	oc_proj;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	
	oc = subtract(origin, obj->center);
	*axis = normalize(obj->norm_vector);
	d_proj = subtract(direction, scale(*axis, dot_product(direction, *axis)));
	oc_proj = subtract(oc, scale(*axis, dot_product(oc, *axis)));
	a = dot_product(d_proj, d_proj);
	b = 2 * dot_product(oc_proj, d_proj);
	c = dot_product(oc_proj, oc_proj) - obj->radius * obj->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	*t1 = (-b -  sqrt(discriminant)) / (2 * a);
	*t2 = (-b +  sqrt(discriminant)) / (2 * a);
	return (1);
}
