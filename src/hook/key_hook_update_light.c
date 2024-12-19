/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:49:30 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 22:14:03 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	key_hook_update_light_move(int keycode, t_data *data);
static int	key_hook_update_light_rotate(int keycode, t_data *data);

int	key_hook_update_light(int keycode, t_data *data)
{
	if (data->hook.light == HOOK_LIGHT_NONE)
	{
		if (keycode == M_LIGHT_MOVE)
			data->hook.light = HOOK_LIGHT_MOVE;
		else if (keycode == M_LIGHT_ROTATE)
			data->hook.light = HOOK_LIGHT_ROTATE;
		else if (keycode == M_BACK)
			data->hook.elem = HOOK_ELEM_NONE;
		else
			return (0);
		return (1);
	}
	if (data->hook.light == HOOK_LIGHT_MOVE)
		return (key_hook_update_light_move(keycode, data));
	else if (data->hook.light == HOOK_LIGHT_ROTATE)
		return (key_hook_update_light_rotate(keycode, data));
	return (0);
}

static int	key_hook_update_light_move(int keycode, t_data *data)
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
			data->light.position.x += 1;
		else if (data->hook.axis == HOOK_AXIS_Y)
			data->light.position.y += 1;
		else if (data->hook.axis == HOOK_AXIS_Z)
			data->light.position.z += 1;
		else
			return (0);
		raytracing(data);
		hook_init(&data->hook);
		return (1);
	}
	else if (keycode == M_RESIZE_DOWN)
	{
		if (data->hook.axis == HOOK_AXIS_X)
			data->light.position.x -= 1;
		else if (data->hook.axis == HOOK_AXIS_Y)
			data->light.position.y -= 1;
		else if (data->hook.axis == HOOK_AXIS_Z)
			data->light.position.z -= 1;
		else
			return (0);
		raytracing(data);
		hook_init(&data->hook);
		return (1);
	}
	return (0);
}

static int	key_hook_update_light_rotate(int keycode, t_data *data)
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
