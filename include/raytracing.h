/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:26:05 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/19 20:20:02 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "include.h"
# include "macro.h"
# include "struct.h"
# include "util.h"
# include "wrap.h"

void		raytracing(t_data *data);
int			intersect(t_vec origin, t_vec direction, t_closest_obj *find_obj);
int			intersect_sphere(t_vec origin, t_vec direction,
				t_closest_obj *find_obj);
int			intersect_cylinder(t_vec origin, t_vec direction,
				t_closest_obj *find_obj);
int			intersect_plane(t_vec origin, t_vec direction, t_closest_obj *find_obj);

t_vec		subtract(t_vec v1, t_vec v2);
t_vec		add(t_vec v1, t_vec v2);
t_vec		scale(t_vec v, double scalar);
double		dot_product(t_vec v1, t_vec v2);
t_vec		cross_product(t_vec v1, t_vec v2);
t_vec		normalize(t_vec v);

t_color		compute_lighting(t_data *data, t_vec point, t_vec normal,
				t_object *obj);
void		find_nearest_object(t_list *objects, t_vec origin, t_vec direction,
				t_closest_obj *find_obj);
t_vec		calculate_ray_direction(t_data data, int x, int y);

void		hook_init(t_hook *hook);
int			key_hook_loop(int keycode, t_data *data);

void		prompt(t_data *data);
void		prompt_elem(t_data *data);
void		prompt_object(t_data *data);
void		prompt_light(t_data *data);
void		prompt_camera(t_data *data);

void		key_hook_update(int keycode, t_data *data);
void		key_hook_update_object(int keycode, t_data *data);
void		key_hook_update_camera(int keycode, t_data *data);
void		key_hook_update_light(int keycode, t_data *data);

t_object	*hook_lst_at(t_data *data, int idx);
t_vec		rotate_x(t_vec vec, double angle);
t_vec		rotate_y(t_vec vec, double angle);
t_vec		rotate_z(t_vec vec, double angle);

#endif