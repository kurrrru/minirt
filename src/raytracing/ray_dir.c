/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:32:48 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 00:58:49 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracing.h"

static t_basis	get_basis(t_camera camera);
static t_vec	add_basis(t_basis basis, double px, double py,
					double fov_scale);
static t_vec	calculate_right(t_vec forward);

t_vec	calculate_ray_direction(t_data data, int x, int y)
{
	double	px;
	double	py;
	double	fov_scale;
	t_basis	basis;

	fov_scale = tan((data.camera.fov * M_PI / 180.0) / 2.0);
	px = (2.0 * ((double)x + 0.5) / (double)data.img.width - 1.0)
		* ((double)data.img.width / (double)data.img.height);
	py = (1.0 - 2.0 * ((double)y + 0.5) / (double)data.img.height);
	basis = get_basis(data.camera);
	return (normalize(add_basis(basis, px, py, fov_scale)));
}

static t_vec	add_basis(t_basis basis, double px, double py, double fov_scale)
{
	t_vec	added;

	added = add(scale(basis.right, px * fov_scale), scale(basis.up, py
				* fov_scale));
	added = add(scale(basis.forward, 1.0), added);
	return (added);
}

static t_vec	calculate_right(t_vec forward)
{
	t_vec	right_dir;
	t_vec	y_axis;
	t_vec	z_axis;

	y_axis = (t_vec){0, 1, 0};
	z_axis = (t_vec){0, 0, 1};
	right_dir = normalize(cross_product(y_axis, forward));
	if (fabs(forward.y) == 1.0)
		right_dir = normalize(cross_product(z_axis, forward));
	return (right_dir);
}

static t_basis	get_basis(t_camera camera)
{
	t_basis	basis;

	basis.forward = camera.orientation;
	basis.right = calculate_right(basis.forward);
	basis.up = cross_product(basis.forward, basis.right);
	return (basis);
}
