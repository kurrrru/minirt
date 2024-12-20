/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_obj_move.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:32:40 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 17:44:32 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	key_hook_update_object_move_axis(int keycode, t_data *data);
static int	key_hook_update_object_move_up(int keycode, t_data *data);
static int	key_hook_update_object_move_down(int keycode, t_data *data);

int	key_hook_update_object_move(int keycode, t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
		return (key_hook_update_object_move_axis(keycode, data));
	if (keycode == M_BACK)
	{
		data->hook.axis = HOOK_AXIS_NONE;
		return (1);
	}
	if (keycode == M_AXIS_UP)
		return (key_hook_update_object_move_up(keycode, data));
	else if (keycode == M_AXIS_DOWN)
		return (key_hook_update_object_move_down(keycode, data));
	return (0);
}

static int	key_hook_update_object_move_axis(int keycode, t_data *data)
{
	if (keycode == M_AXIS_X)
		data->hook.axis = HOOK_AXIS_X;
	else if (keycode == M_AXIS_Y)
		data->hook.axis = HOOK_AXIS_Y;
	else if (keycode == M_AXIS_Z)
		data->hook.axis = HOOK_AXIS_Z;
	else if (keycode == M_BACK)
		data->hook.obj = HOOK_OBJ_NONE;
	else
		return (0);
	return (1);
}

static int	key_hook_update_object_move_up(int keycode, t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_X)
		((t_object *)data->objects->content)->center.x += 1;
	else if (data->hook.axis == HOOK_AXIS_Y)
		((t_object *)data->objects->content)->center.y += 1;
	else if (data->hook.axis == HOOK_AXIS_Z)
		((t_object *)data->objects->content)->center.z += 1;
	raytracing(data);
	hook_init(&data->hook);
	return (1);
}

static int	key_hook_update_object_move_down(int keycode, t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_X)
		((t_object *)data->objects->content)->center.x -= 1;
	else if (data->hook.axis == HOOK_AXIS_Y)
		((t_object *)data->objects->content)->center.y -= 1;
	else if (data->hook.axis == HOOK_AXIS_Z)
		((t_object *)data->objects->content)->center.z -= 1;
	raytracing(data);
	hook_init(&data->hook);
	return (1);
}
