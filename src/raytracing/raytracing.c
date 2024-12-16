/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:17:27 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/16 23:21:16 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static t_vec	calculate_ray_direction(t_data data, int x, int y);
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

static t_vec calculate_ray_direction(t_data data, int x, int y)
{
    t_vec ray_dir;
    t_vec forward;
    t_vec right;
    t_vec up;
    double px, py, fov_scale;

    fov_scale = tan((data.camera.fov * M_PI / 180.0) / 2.0);
    forward = data.camera.orientation;
    if (fabs(forward.y) == 1.0)
        right = normalize(cross_product((t_vec){0, 0, 1}, forward));
    else
        right = normalize(cross_product((t_vec){0, 1, 0}, forward));
    up = cross_product(forward, right);
    px = (2.0 * ((double)x + 0.5) / (double)data.img.width - 1.0) * ((double)data.img.width / (double)data.img.height);
    py = (1.0 - 2.0 * ((double)y + 0.5) / (double)data.img.height);
    ray_dir = add(scale(forward, 1.0), add(scale(right, px * fov_scale),
                scale(up, py * fov_scale)));
    return normalize(ray_dir);
}

static t_color	trace_ray(t_data *data, t_vec origin, t_vec direction)
{
	t_object	*closest_obj;
	double		min_dist;
	t_color		final_color;

	closest_obj = NULL;
	t_vec intersection_point, normal;
	min_dist = INFINITY;
	final_color.red = 0;
	final_color.green = 0;
	final_color.blue = 0;
	find_nearest_object(data->objects, origin, direction, &closest_obj,
		&intersection_point, &normal, &min_dist);
	if (closest_obj)
	{
		final_color = compute_lighting(data, intersection_point, normal,
				closest_obj);
	}
	return (final_color);
}

void	find_nearest_object(t_list *objects, t_vec origin, t_vec direction,
		t_object **closest_obj, t_vec *intersection, t_vec *normal,
		double *min_dist)
{
	t_object	*obj;
	double		dist;

	t_vec temp_intersection, temp_normal;
	*closest_obj = NULL;
	while (objects)
	{
		obj = (t_object *)objects->content;
		dist = *min_dist;
		if (intersect(obj, origin, direction, &dist, &temp_intersection,
				&temp_normal) && dist < *min_dist && dist > 1e-6)
		{
			*min_dist = dist;
			*closest_obj = obj;
			*intersection = temp_intersection;
			*normal = temp_normal;
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
