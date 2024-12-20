/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy_two_bases.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:05:30 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 11:18:54 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	intersect_cy_top_base(t_vec direction, t_vec oc, t_object *obj)
{
	const double	invalid_t = -1;
	double			t;
	double			divisor;
	t_vec			vec_from_center;

	divisor = dot_product(direction, obj->norm_vector);
	if (divisor == 0)
		return (invalid_t);
	t = -(dot_product(oc, obj->norm_vector) + obj->height / 2) / divisor;
	if (t < 0)
		return (invalid_t);
	vec_from_center = add(add(oc, scale(direction, t)),
			scale(obj->norm_vector, obj->height / 2));
	if (sqrt(dot_product(vec_from_center, vec_from_center)) > obj->radius)
		return (invalid_t);
	return (t);
}

double	intersect_cy_bottom_base(t_vec direction, t_vec oc, t_object *obj)
{
	const double	invalid_t = -1;
	double			t;
	double			divisor;
	t_vec			vec_from_center;

	divisor = dot_product(direction, obj->norm_vector);
	if (divisor == 0)
		return (invalid_t);
	t = -(dot_product(oc, obj->norm_vector) - obj->height / 2) / divisor;
	if (t < 0)
		return (invalid_t);
	vec_from_center = add(add(oc, scale(direction, t)),
			scale(obj->norm_vector, -obj->height / 2));
	if (sqrt(dot_product(vec_from_center, vec_from_center)) > obj->radius)
		return (invalid_t);
	return (t);
}
