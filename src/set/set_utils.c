/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:56:23 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 22:10:20 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

t_vec	parse_vec(char *str)
{
	t_vec	vec;
	char	**coords;

	coords = xsplit(str, ',');
	if (array_len(coords) != 3)
		msg_exit("Invalid input");
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

	components = xsplit(str, ',');
	if (array_len(components) != 3)
		msg_exit("Invalid input");
	color.red = ft_atof(components[0]);
	color.green = ft_atof(components[1]);
	color.blue = ft_atof(components[2]);
	if (color.red < 0 || color.red > 255 || color.green < 0 || color.green > 255
		|| color.blue < 0 || color.blue > 255)
	{
		free_ptrarr((void **)components);
		return ((t_color){-1, -1, -1});
	}
	free_ptrarr((void **)components);
	return (color);
}

int	array_len(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}
