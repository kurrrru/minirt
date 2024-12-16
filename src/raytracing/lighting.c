/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:17:06 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 00:58:46 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static t_color	clamp_color(t_color color);
static bool		has_shadow(t_list *objects, t_vec hit_point, t_vec light_pos);

t_color	compute_lighting(t_data *data, t_vec point, t_vec normal, t_object *obj)
{
	t_color	result;
	t_vec	light_dir;
	double	diffuse_intensity;
	double	dot;

	result.red = data->ambient.red * obj->color.red / 255;
	result.green = data->ambient.green * obj->color.green / 255;
	result.blue = data->ambient.blue * obj->color.blue / 255;
	light_dir = normalize(subtract(data->light.position, point));
	if (has_shadow(data->objects, point, data->light.position))
		return (clamp_color(result));
	dot = fmax(0, dot_product(normal, light_dir));
	diffuse_intensity = dot * data->light.intensity;
	result.red += obj->color.red * data->light.color.red / 255
		* diffuse_intensity;
	result.green += obj->color.green * data->light.color.green / 255
		* diffuse_intensity;
	result.blue += obj->color.blue * data->light.color.blue / 255
		* diffuse_intensity;
	return (clamp_color(result));
}

static bool	has_shadow(t_list *objects, t_vec hit_point, t_vec light_pos)
{
	t_vec			shadow_dir;
	double			light_dist;
	t_closest_obj	find_shadow;

	shadow_dir = subtract(light_pos, hit_point);
	light_dist = sqrt(dot_product(shadow_dir, shadow_dir));
	shadow_dir = normalize(shadow_dir);
	find_shadow.min_dist = light_dist;
	find_nearest_object(objects, hit_point, shadow_dir, &find_shadow);
	if (find_shadow.closest_obj != NULL && find_shadow.min_dist < light_dist)
		return (true);
	return (false);
}

static t_color	clamp_color(t_color color)
{
	color.red = fmin(255, fmax(0, color.red));
	color.green = fmin(255, fmax(0, color.green));
	color.blue = fmin(255, fmax(0, color.blue));
	return (color);
}
