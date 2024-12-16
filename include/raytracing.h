/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:26:05 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/16 00:28:55 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "include.h"
# include "macro.h"
# include "struct.h"
# include "util.h"
# include "wrap.h"

void	raytracing(t_data *data);
int		intersect(t_object *obj, t_vec origin, t_vec direction, double *dist,
			t_vec *intersection, t_vec *normal);
int	intersect_plane(t_object *obj, t_vec origin, t_vec direction,
		double *dist, t_vec *intersection, t_vec *normal);
int	intersect_sphere(t_object *obj, t_vec origin, t_vec direction,
		double *dist, t_vec *intersection, t_vec *normal);
int	intersect_cylinder(t_object *obj, t_vec origin, t_vec direction,
		double *dist, t_vec *intersection, t_vec *normal);

t_vec	subtract(t_vec v1, t_vec v2);
t_vec	add(t_vec v1, t_vec v2);
t_vec	scale(t_vec v, double scalar);
double	dot_product(t_vec v1, t_vec v2);
t_vec	cross_product(t_vec v1, t_vec v2);
t_vec	normalize(t_vec v);

t_color	compute_lighting(t_data *data, t_vec point, t_vec normal,
		t_object *obj);
void	find_nearest_object(t_list *objects, t_vec origin, t_vec direction,
		t_object **closest_obj, t_vec *intersection, t_vec *normal,
		double *min_dist);

#endif