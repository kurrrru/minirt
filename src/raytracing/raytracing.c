/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:17:27 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 00:58:52 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static t_color	trace_ray(t_data *data, t_vec origin, t_vec direction);
static void		set_pixel_color(t_image *img, int x, int y, t_color color);

void	raytracing(t_data *data)
{
	t_color	pixel_color;
	t_vec	ray_direction;
	int		x;
	int		y;

	y = -1;
	while (++y < data->img.height)
	{
		x = -1;
		while (++x < data->img.width)
		{
			ray_direction = calculate_ray_direction(*data, x, y);
			pixel_color = trace_ray(data, data->camera.position, ray_direction);
			set_pixel_color(&data->img, x, y, pixel_color);
		}
	}
}

static t_color	trace_ray(t_data *data, t_vec origin, t_vec direction)
{
	t_closest_obj	find_obj;

	find_obj.closest_obj = NULL;
	find_obj.min_dist = INFINITY;
	find_obj.final_color.red = 0;
	find_obj.final_color.green = 0;
	find_obj.final_color.blue = 0;
	find_nearest_object(data->objects, origin, direction, &find_obj);
	if (find_obj.closest_obj)
	{
		find_obj.final_color = compute_lighting(data,
				find_obj.intersection_point, find_obj.normal,
				find_obj.closest_obj);
	}
	return (find_obj.final_color);
}

void	find_nearest_object(t_list *objects, t_vec origin, t_vec direction,
		t_closest_obj *find_obj)
{
	t_closest_obj	get_obj;

	while (objects)
	{
		get_obj.closest_obj = (t_object *)objects->content;
		get_obj.min_dist = find_obj->min_dist;
		if (intersect(origin, direction, &get_obj)
			&& get_obj.min_dist < find_obj->min_dist && get_obj.min_dist > 1e-6)
		{
			find_obj->min_dist = get_obj.min_dist;
			find_obj->closest_obj = get_obj.closest_obj;
			find_obj->intersection_point = get_obj.intersection_point;
			find_obj->normal = get_obj.normal;
		}
		objects = objects->next;
	}
}

static void	set_pixel_color(t_image *img, int x, int y, t_color color)
{
	char	*pixel;

	pixel = img->address + (y * img->width + x) * (img->bpp / 8);
	pixel[0] = (char)color.blue;
	pixel[1] = (char)color.green;
	pixel[2] = (char)color.red;
}
