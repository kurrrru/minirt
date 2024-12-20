/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_obj_resize.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:32:45 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 13:34:01 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	key_hook_update_object_resize(int keycode, t_data *data)
{
	if (data->hook.resize == HOOK_RESIZE_NONE)
	{
		if (keycode == M_RESIZE_DIAMETER
			&& ((t_object *)data->objects->content)->shape == SPHERE)
			data->hook.resize = HOOK_RESIZE_DIAMETER;
		else if (keycode == M_RESIZE_WIDTH
			&& ((t_object *)data->objects->content)->shape == CYLINDER)
			data->hook.resize = HOOK_RESIZE_WIDTH;
		else if (keycode == M_RESIZE_HEIGHT
			&& ((t_object *)data->objects->content)->shape == CYLINDER)
			data->hook.resize = HOOK_RESIZE_HEIGHT;
		else if (keycode == M_BACK)
			data->hook.obj = HOOK_OBJ_NONE;
		else
			return (0);
		return (1);
	}
	if (keycode == M_BACK)
	{
		data->hook.resize = HOOK_RESIZE_NONE;
		return (1);
	}
	if (data->hook.resize == HOOK_RESIZE_DIAMETER
		|| data->hook.resize == HOOK_RESIZE_WIDTH)
	{
		if (keycode == M_RESIZE_UP)
			((t_object *)data->objects->content)->radius *= 1.1;
		else if (keycode == M_RESIZE_DOWN)
			((t_object *)data->objects->content)->radius /= 1.1;
		else
			return (0);
		raytracing(data);
		hook_init(&data->hook);
		return (1);
	}
	else if (data->hook.resize == HOOK_RESIZE_HEIGHT)
	{
		if (keycode == M_RESIZE_UP)
			((t_object *)data->objects->content)->height *= 1.1;
		else if (keycode == M_RESIZE_DOWN)
			((t_object *)data->objects->content)->height /= 1.1;
		else
			return (0);
		raytracing(data);
		hook_init(&data->hook);
		return (1);
	}
	return (0);
}
