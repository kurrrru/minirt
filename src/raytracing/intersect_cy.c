/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:20:54 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 17:46:35 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static int	check_intersect(double *t, t_object *obj, t_vec origin,
				t_vec direction);
static int	calc_t(t_vec d_proj, t_vec oc_proj, double *t, t_object *obj);

int	intersect_cylinder(t_vec origin, t_vec direction, t_closest_obj *find_obj)
{
	double	t;
	t_vec	temp_normal;

	if (check_intersect(&t, find_obj->closest_obj, origin, direction) == 0)
		return (0);
	if (t > 0 && t < find_obj->min_dist)
		find_obj->min_dist = t;
	else
		return (0);
	find_obj->intersection_point = add(origin, scale(direction,
				find_obj->min_dist));
	temp_normal = subtract(find_obj->intersection_point,
			find_obj->closest_obj->center);
	find_obj->normal = normalize(subtract(temp_normal,
				scale(find_obj->closest_obj->norm_vector,
					dot_product(temp_normal,
						find_obj->closest_obj->norm_vector))));
	return (1);
}

static int	check_intersect(double *t, t_object *obj, t_vec origin,
		t_vec direction)
{
	t_vec	oc;
	t_vec	d_proj;
	t_vec	oc_proj;

	oc = subtract(origin, obj->center);
	d_proj = subtract(direction, scale(obj->norm_vector, dot_product(direction,
					obj->norm_vector)));
	oc_proj = subtract(oc, scale(obj->norm_vector, dot_product(oc,
					obj->norm_vector)));
	return (calc_t(d_proj, oc_proj, t, obj));
}

static int	calc_t(t_vec d_proj, t_vec oc_proj, double *t, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = dot_product(d_proj, d_proj);
	b = 2 * dot_product(oc_proj, d_proj);
	c = dot_product(oc_proj, oc_proj) - obj->radius * obj->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	*t = fmin((-b - sqrt(discriminant)) / (2 * a), (-b + sqrt(discriminant))
			/ (2 * a));
	return (1);
}
