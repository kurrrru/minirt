/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:56:23 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/13 23:37:15 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

t_vec	parse_vec(char *str)
{
	t_vec	vec;
	char	**coords;

	coords = ft_split(str, ',');
	if (!coords || !coords[0] || !coords[1] || !coords[2] || coords[3])
		return ((t_vec){-1, -1, -1});
	vec.x = ft_atof(coords[0]);
	vec.y = ft_atof(coords[1]);
	vec.z = ft_atof(coords[2]);
	free_ptrarr((void **)coords);
	return (vec);
}

t_color	parse_color(char *str)
{
	t_color	color;
	char	**components;

	components = ft_split(str, ',');
	if (!components || !components[0] || !components[1] || !components[2]
		|| components[3])
		return ((t_color){-1, -1, -1});
	color.red = ft_atof(components[0]) / 255.0;
	color.green = ft_atof(components[1]) / 255.0;
	color.blue = ft_atof(components[2]) / 255.0;
	free_ptrarr((void **)components);
	return (color);
}
