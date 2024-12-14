/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:53:49 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 14:12:48 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

static int	validate_cylinder_color(t_color *color, char **params);
static int	parse_cylinder_values(t_vec *position, t_vec *orientation,
				double *values, char **params);

int	set_cylinder(t_data *data, char **params)
{
	t_vec		position;
	t_vec		orientation;
	t_color		color;
	t_object	*cylinder;
	double		values[2];

	if (parse_cylinder_values(&position, &orientation, values, params) == -1
		|| validate_cylinder_color(&color, params) == -1)
		return (-1);
	cylinder = xmalloc(sizeof(t_object));
	if (!cylinder)
		return (-1);
	*cylinder = (t_object){CYLINDER, position, orientation, values[0] / 2,
		values[1], color};
	ft_lstadd_back(&(data->objects), ft_lstnew(cylinder));
	return (0);
}

static int	parse_cylinder_values(t_vec *position, t_vec *orientation,
		double *values, char **params)
{
	*position = parse_vec(params[0]);
	*orientation = parse_vec(params[1]);
	values[0] = ft_atof(params[2]);
	values[1] = ft_atof(params[3]);
	if (params[4] == NULL || params[5])
		return (-1);
	if (position->x == -1 || orientation->x == -1)
		return (-1);
	if (values[0] <= 0 || values[1] <= 0)
		return (-1);
	return (0);
}

static int	validate_cylinder_color(t_color *color, char **params)
{
	*color = parse_color(params[4]);
	if (color->red < 0 || color->green < 0 || color->blue < 0)
		return (-1);
	return (0);
}
