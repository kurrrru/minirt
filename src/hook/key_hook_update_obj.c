/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:32:01 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 20:27:16 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	key_hook_update_object_resize(int keycode, t_data *data);
static void	key_hook_update_object_move(int keycode, t_data *data);
static void	key_hook_update_object_rotate(int keycode, t_data *data);

void	key_hook_update_object(int keycode, t_data *data)
{
	if (data->hook.idx_selected == -1)
	{
		if (keycode == M_OBJ_NEXT)
		{
			if (data->hook.idx_displayed < ft_lstsize(data->objects) - 1)
				data->hook.idx_displayed++;
			else
				data->hook.idx_displayed = 0;
		}
		else if (keycode == M_OBJ_THIS) // もしplaneなら"this object cannot be selected"と表示
		{
			data->hook.idx_selected = data->hook.idx_displayed;
			data->hook.idx_displayed = 0;
		}
		else if (keycode == M_OBJ_PREV)
		{
			if (data->hook.idx_displayed > 0)
				data->hook.idx_displayed--;
			else
				data->hook.idx_displayed = ft_lstsize(data->objects) - 1;
		}
		else if (keycode == M_BACK)
			data->hook.elem = HOOK_ELEM_NONE;
		return ;
	}
	if (data->hook.obj == HOOK_OBJ_NONE)
	{
		if (keycode == M_OBJ_RESIZE)
			data->hook.obj = HOOK_OBJ_RESIZE;
		else if (keycode == M_OBJ_MOVE)
			data->hook.obj = HOOK_OBJ_MOVE;
		else if (keycode == M_OBJ_ROTATE)
			data->hook.obj = HOOK_OBJ_ROTATE;
		else if (keycode == M_BACK)
			data->hook.idx_selected = -1;
	}
	else if (data->hook.obj == HOOK_OBJ_RESIZE)
		key_hook_update_object_resize(keycode, data);
	else if (data->hook.obj == HOOK_OBJ_MOVE)
		key_hook_update_object_move(keycode, data);
	else if (data->hook.obj == HOOK_OBJ_ROTATE)
		key_hook_update_object_rotate(keycode, data);
}

static void	key_hook_update_object_resize(int keycode, t_data *data)
{
	if (data->hook.resize == HOOK_RESIZE_NONE)
	{
		if (keycode == M_RESIZE_DIAMETER && ((t_object *)data->objects->content)->shape == SPHERE)
			data->hook.resize = HOOK_RESIZE_DIAMETER;
		else if (keycode == M_RESIZE_WIDTH && ((t_object *)data->objects->content)->shape == CYLINDER)
			data->hook.resize = HOOK_RESIZE_WIDTH;
		else if (keycode == M_RESIZE_HEIGHT && ((t_object *)data->objects->content)->shape == CYLINDER)
			data->hook.resize = HOOK_RESIZE_HEIGHT;
		else if (keycode == M_BACK)
			data->hook.obj = HOOK_OBJ_NONE;
		return ;
	}
	if (keycode == M_BACK)
	{
		data->hook.resize = HOOK_RESIZE_NONE;
		return ;
	}
	if (data->hook.resize == HOOK_RESIZE_DIAMETER || data->hook.resize == HOOK_RESIZE_WIDTH)
	{
		if (keycode == M_RESIZE_UP)
			((t_object *)data->objects->content)->radius *= 1.1;
		else if (keycode == M_RESIZE_DOWN)
			((t_object *)data->objects->content)->radius /= 1.1;
		else
			return ;
		raytracing(data);
		hook_init(&data->hook);
	}
	else if (data->hook.resize == HOOK_RESIZE_HEIGHT)
	{
		if (keycode == M_RESIZE_UP)
			((t_object *)data->objects->content)->height *= 1.1;
		else if (keycode == M_RESIZE_DOWN)
			((t_object *)data->objects->content)->height /= 1.1;
		else
			return ;
		raytracing(data);
		hook_init(&data->hook);
	}
}

static void	key_hook_update_object_move(int keycode, t_data *data)
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
			data->hook.obj = HOOK_OBJ_NONE;
		return ;
	}
	if (keycode == M_BACK)
	{
		data->hook.axis = HOOK_AXIS_NONE;
		return ;
	}
	if (keycode == M_RESIZE_UP)
	{
		if (data->hook.axis == HOOK_AXIS_X)
			((t_object *)data->objects->content)->center.x += 1;
		else if (data->hook.axis == HOOK_AXIS_Y)
			((t_object *)data->objects->content)->center.y += 1;
		else if (data->hook.axis == HOOK_AXIS_Z)
			((t_object *)data->objects->content)->center.z += 1;
	}
	else if (keycode == M_RESIZE_DOWN)
	{
		if (data->hook.axis == HOOK_AXIS_X)
			((t_object *)data->objects->content)->center.x -= 1;
		else if (data->hook.axis == HOOK_AXIS_Y)
			((t_object *)data->objects->content)->center.y -= 1;
		else if (data->hook.axis == HOOK_AXIS_Z)
			((t_object *)data->objects->content)->center.z -= 1;
	}
	else
		return ;
	raytracing(data);
	hook_init(&data->hook);
}

static void	key_hook_update_object_rotate(int keycode, t_data *data)
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
			data->hook.obj = HOOK_OBJ_NONE;
		return ;
	}
	if (keycode == M_BACK)
	{
		data->hook.axis = HOOK_AXIS_NONE;
		return ;
	}
	if (keycode == M_RESIZE_UP)
	{
		if (data->hook.axis == HOOK_AXIS_X)
			((t_object *)data->objects->content)->norm_vector = rotate_x(((t_object *)data->objects->content)->norm_vector, 5);
		else if (data->hook.axis == HOOK_AXIS_Y)
			((t_object *)data->objects->content)->norm_vector = rotate_y(((t_object *)data->objects->content)->norm_vector, 5);
		else if (data->hook.axis == HOOK_AXIS_Z)
			((t_object *)data->objects->content)->norm_vector = rotate_z(((t_object *)data->objects->content)->norm_vector, 5);
	}
	else if (keycode == M_RESIZE_DOWN)
	{
		if (data->hook.axis == HOOK_AXIS_X)
			((t_object *)data->objects->content)->norm_vector = rotate_x(((t_object *)data->objects->content)->norm_vector, -5);
		else if (data->hook.axis == HOOK_AXIS_Y)
			((t_object *)data->objects->content)->norm_vector = rotate_y(((t_object *)data->objects->content)->norm_vector, -5);
		else if (data->hook.axis == HOOK_AXIS_Z)
			((t_object *)data->objects->content)->norm_vector = rotate_z(((t_object *)data->objects->content)->norm_vector, -5);
	}
	else
		return ;
	raytracing(data);
	hook_init(&data->hook);
}
