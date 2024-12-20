/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_camera_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:31:51 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 22:25:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	key_hook_update_camera_rotate_axis(int keycode, t_data *data);
static int	key_hook_update_camera_rotate_up(int keycode, t_data *data);
static int	key_hook_update_camera_rotate_down(int keycode, t_data *data);

int	key_hook_update_camera_rotate(int keycode, t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
		return (key_hook_update_camera_rotate_axis(keycode, data));
	if (keycode == M_BACK)
	{
		data->hook.axis = HOOK_AXIS_NONE;
		return (1);
	}
	if (keycode == M_AXIS_UP)
		return (key_hook_update_camera_rotate_up(keycode, data));
	else if (keycode == M_AXIS_DOWN)
		return (key_hook_update_camera_rotate_down(keycode, data));
	return (0);
}

static int	key_hook_update_camera_rotate_axis(int keycode, t_data *data)
{
	if (keycode == M_AXIS_X)
		data->hook.axis = HOOK_AXIS_X;
	else if (keycode == M_AXIS_Y)
		data->hook.axis = HOOK_AXIS_Y;
	else if (keycode == M_AXIS_Z)
		data->hook.axis = HOOK_AXIS_Z;
	else if (keycode == M_BACK)
		data->hook.camera = HOOK_CAMERA_NONE;
	else
		return (0);
	return (1);
}

static int	key_hook_update_camera_rotate_up(int keycode, t_data *data)
{
	(void)keycode;
	if (data->hook.axis == HOOK_AXIS_X)
		data->camera.orientation = rotate_x(data->camera.orientation, 1);
	else if (data->hook.axis == HOOK_AXIS_Y)
		data->camera.orientation = rotate_y(data->camera.orientation, 1);
	else if (data->hook.axis == HOOK_AXIS_Z)
		data->camera.orientation = rotate_z(data->camera.orientation, 1);
	else
		return (0);
	raytracing(data);
	hook_init(&data->hook);
	return (1);
}

static int	key_hook_update_camera_rotate_down(int keycode, t_data *data)
{
	(void)keycode;
	if (data->hook.axis == HOOK_AXIS_X)
		data->camera.orientation = rotate_x(data->camera.orientation, -1);
	else if (data->hook.axis == HOOK_AXIS_Y)
		data->camera.orientation = rotate_y(data->camera.orientation, -1);
	else if (data->hook.axis == HOOK_AXIS_Z)
		data->camera.orientation = rotate_z(data->camera.orientation, -1);
	else
		return (0);
	raytracing(data);
	hook_init(&data->hook);
	return (1);
}
