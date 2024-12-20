/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_light_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:29:44 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 13:29:50 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	key_hook_update_light_rotate(int keycode, t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
	{
		if (keycode == M_AXIS_X)
			data->hook.axis = HOOK_AXIS_X;
		else if (keycode == M_AXIS_Y)
			data->hook.axis = HOOK_AXIS_Y;
		else if (keycode == M_AXIS_Z)
			data->hook.axis = HOOK_AXIS_Z;
		else if (keycode == M_BACK)
			data->hook.light = HOOK_LIGHT_NONE;
		else
			return (0);
		return (1);
	}
	if (keycode == M_BACK)
	{
		data->hook.axis = HOOK_AXIS_NONE;
		return (1);
	}
	if (keycode == M_RESIZE_UP)
	{
		if (data->hook.axis == HOOK_AXIS_X)
			data->light.position = rotate_x(data->light.position, 5);
		else if (data->hook.axis == HOOK_AXIS_Y)
			data->light.position = rotate_y(data->light.position, 5);
		else if (data->hook.axis == HOOK_AXIS_Z)
			data->light.position = rotate_z(data->light.position, 5);
		else
			return (0);
		raytracing(data);
		hook_init(&data->hook);
		return (1);
	}
	else if (keycode == M_RESIZE_DOWN)
	{
		if (data->hook.axis == HOOK_AXIS_X)
			data->light.position = rotate_x(data->light.position, -5);
		else if (data->hook.axis == HOOK_AXIS_Y)
			data->light.position = rotate_y(data->light.position, -5);
		else if (data->hook.axis == HOOK_AXIS_Z)
			data->light.position = rotate_z(data->light.position, -5);
		else
			return (0);
		raytracing(data);
		hook_init(&data->hook);
		return (1);
	}
	return (0);
}
