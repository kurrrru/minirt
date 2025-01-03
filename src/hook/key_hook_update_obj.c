/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:32:01 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 22:48:42 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	key_hook_update_object_op(int keycode, t_data *data);
static int	key_hook_update_object_select(int keycode, t_data *data);
static int	key_hook_update_object_select_end(int keycode, t_data *data);

int	key_hook_update_object(int keycode, t_data *data)
{
	if (data->hook.idx_selected == -1)
		return (key_hook_update_object_select(keycode, data));
	if (data->hook.obj == HOOK_OBJ_NONE)
		return (key_hook_update_object_op(keycode, data));
	else if (data->hook.obj == HOOK_OBJ_RESIZE)
		return (key_hook_update_object_resize(keycode, data));
	else if (data->hook.obj == HOOK_OBJ_MOVE)
		return (key_hook_update_object_move(keycode, data));
	else if (data->hook.obj == HOOK_OBJ_ROTATE)
		return (key_hook_update_object_rotate(keycode, data));
	return (0);
}

static int	key_hook_update_object_op(int keycode, t_data *data)
{
	if (keycode == M_OBJ_RESIZE
		&& hook_lst_at(data, data->hook.idx_selected)->shape != PLANE)
		data->hook.obj = HOOK_OBJ_RESIZE;
	else if (keycode == M_OBJ_MOVE)
		data->hook.obj = HOOK_OBJ_MOVE;
	else if (keycode == M_OBJ_ROTATE
		&& hook_lst_at(data, data->hook.idx_selected)->shape != SPHERE)
		data->hook.obj = HOOK_OBJ_ROTATE;
	else if (keycode == M_BACK)
		data->hook.idx_selected = -1;
	else
		return (0);
	return (1);
}

static int	key_hook_update_object_select(int keycode, t_data *data)
{
	if (keycode == M_OBJ_NEXT)
	{
		if (data->hook.idx_displayed < ft_lstsize(data->objects) - 1)
			data->hook.idx_displayed++;
		else
			data->hook.idx_displayed = 0;
		return (1);
	}
	else if (keycode == M_OBJ_THIS)
		return (key_hook_update_object_select_end(keycode, data));
	else if (keycode == M_OBJ_PREV)
	{
		if (data->hook.idx_displayed > 0)
			data->hook.idx_displayed--;
		else
			data->hook.idx_displayed = ft_lstsize(data->objects) - 1;
		return (1);
	}
	else if (keycode == M_BACK)
	{
		data->hook.elem = HOOK_ELEM_NONE;
		data->hook.idx_displayed = 0;
		return (1);
	}
	return (0);
}

static int	key_hook_update_object_select_end(int keycode, t_data *data)
{
	(void)keycode;
	data->hook.idx_selected = data->hook.idx_displayed;
	data->hook.idx_displayed = 0;
	return (1);
}
