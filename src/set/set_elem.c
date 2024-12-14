/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:49:35 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 18:37:17 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

int	set_ambient(t_data *data, char **params)
{
	double	ratio;
	t_color	color;

	if (data->ambient.red != -1 || data->ambient.green != -1
		|| data->ambient.blue != -1)
		return (-1);
	if (!params[0] || !params[1] || params[2])
		return (-1);
	ratio = ft_atof(params[0]);
	if (ratio < 0.0 || ratio > 1.0)
		return (-1);
	color = parse_color(params[1]);
	if (color.red < 0 || color.green < 0 || color.blue < 0)
		return (-1);
	data->ambient = (t_color){color.red * ratio, color.green * ratio, color.blue
		* ratio};
	return (0);
}

int	set_camera(t_data *data, char **params)
{
	t_vec	position;
	t_vec	orientation;
	double	fov;

	if (data->camera.fov != -1.0)
		return (-1);
	if (!params[0] || !params[1] || !params[2] || params[3])
		return (-1);
	position = parse_vec(params[0]);
	orientation = parse_vec(params[1]);
	fov = ft_atof(params[2]);
	if (fov < 0 || fov > 180)
		return (-1);
	data->camera = (t_camera){position, orientation, fov};
	return (0);
}

int	set_light(t_data *data, char **params)
{
	t_vec	position;
	t_color	color;
	double	intensity;

	if (data->light.intensity != -1.0)
		return (-1);
	if (!params[0] || !params[1] || !params[2] || params[3])
		return (-1);
	position = parse_vec(params[0]);
	intensity = ft_atof(params[1]);
	color = parse_color(params[2]);
	if (position.x == -1 || intensity < 0.0 || intensity > 1.0 || color.red < 0
		|| color.green < 0 || color.blue < 0)
		return (-1);
	data->light = (t_light){position, color, intensity};
	return (0);
}
