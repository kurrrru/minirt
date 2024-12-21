/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_obj_resize.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:32:45 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 18:01:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	key_hook_update_object_resize_property(int keycode, t_data *data);
static int	key_hook_update_object_resize_radius(int keycode, t_data *data);
static int	key_hook_update_object_resize_height(int keycode, t_data *data);

int	key_hook_update_object_resize(int keycode, t_data *data)
{
	if (data->hook.resize == HOOK_RESIZE_NONE)
		return (key_hook_update_object_resize_property(keycode, data));
	if (keycode == M_BACK)
	{
		data->hook.resize = HOOK_RESIZE_NONE;
		return (1);
	}
	if (data->hook.resize == HOOK_RESIZE_DIAMETER
		|| data->hook.resize == HOOK_RESIZE_WIDTH)
		return (key_hook_update_object_resize_radius(keycode, data));
	else if (data->hook.resize == HOOK_RESIZE_HEIGHT)
		return (key_hook_update_object_resize_height(keycode, data));
	return (0);
}

static int	key_hook_update_object_resize_property(int keycode, t_data *data)
{
	if (keycode == M_RESIZE_DIAMETER
		&& hook_lst_at(data, data->hook.idx_selected)->shape == SPHERE)
		data->hook.resize = HOOK_RESIZE_DIAMETER;
	else if (keycode == M_RESIZE_WIDTH
		&& hook_lst_at(data, data->hook.idx_selected)->shape == CYLINDER)
		data->hook.resize = HOOK_RESIZE_WIDTH;
	else if (keycode == M_RESIZE_HEIGHT
		&& hook_lst_at(data, data->hook.idx_selected)->shape == CYLINDER)
		data->hook.resize = HOOK_RESIZE_HEIGHT;
	else if (keycode == M_BACK)
		data->hook.obj = HOOK_OBJ_NONE;
	else
		return (0);
	return (1);
}

static int	key_hook_update_object_resize_radius(int keycode, t_data *data)
{
	if (keycode == M_RESIZE_UP)
		hook_lst_at(data, data->hook.idx_selected)->radius *= 1.1;
	else if (keycode == M_RESIZE_DOWN)
		hook_lst_at(data, data->hook.idx_selected)->radius /= 1.1;
	else
		return (0);
	raytracing(data);
	hook_init(&data->hook);
	return (1);
}

static int	key_hook_update_object_resize_height(int keycode, t_data *data)
{
	if (keycode == M_RESIZE_UP)
		hook_lst_at(data, data->hook.idx_selected)->height *= 1.1;
	else if (keycode == M_RESIZE_DOWN)
		((t_object *)data->objects->content)->height /= 1.1;
	else
		return (0);
	raytracing(data);
	hook_init(&data->hook);
	return (1);
}
