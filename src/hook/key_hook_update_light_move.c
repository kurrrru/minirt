/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_light_move.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:29:11 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 17:52:43 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	key_hook_update_light_move_axis(int keycode, t_data *data);
static int	key_hook_update_light_move_up(int keycode, t_data *data);
static int	key_hook_update_light_move_down(int keycode, t_data *data);

int	key_hook_update_light_move(int keycode, t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
		return (key_hook_update_light_move_axis(keycode, data));
	if (keycode == M_BACK)
	{
		data->hook.axis = HOOK_AXIS_NONE;
		return (1);
	}
	if (keycode == M_AXIS_UP)
		return (key_hook_update_light_move_up(keycode, data));
	else if (keycode == M_AXIS_DOWN)
		return (key_hook_update_light_move_down(keycode, data));
	return (0);
}

static int	key_hook_update_light_move_axis(int keycode, t_data *data)
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

static int	key_hook_update_light_move_up(int keycode, t_data *data)
{
	(void)keycode;
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

static int	key_hook_update_light_move_down(int keycode, t_data *data)
{
	(void)keycode;
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
