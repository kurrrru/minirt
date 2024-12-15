/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:53:56 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 22:11:52 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

int	set_plane(t_data *data, char **params)
{
	t_vec		position;
	t_vec		normal;
	t_color		color;
	t_object	*plane;

	if (array_len(params) != 3)
		return (-1);
	position = parse_vec(params[0]);
	normal = parse_vec(params[1]);
	color = parse_color(params[2]);
	if (color.red < 0 || color.green < 0 || color.blue < 0)
		return (-1);
	plane = xmalloc(sizeof(t_object));
	*plane = (t_object){PLANE, position, normal, 0, 0, color};
	ft_lstadd_back(&(data->objects), xlstnew(plane));
	return (0);
}
