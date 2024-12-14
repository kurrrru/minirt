/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:54:02 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 18:48:48 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

int	set_sphere(t_data *data, char **params)
{
	t_vec		position;
	double		diameter;
	t_color		color;
	t_object	*sphere;

	if (!params[0] || !params[1] || !params[2] || params[3])
		return (-1);
	position = parse_vec(params[0]);
	diameter = ft_atof(params[1]);
	color = parse_color(params[2]);
	if (diameter <= 0 || color.red < 0 || color.green < 0
		|| color.blue < 0)
		return (-1);
	sphere = xmalloc(sizeof(t_object));
	*sphere = (t_object){SPHERE, position, {0, 0, 0}, diameter / 2, 0, color};
	ft_lstadd_back(&(data->objects), xlstnew(sphere));
	return (0);
}
