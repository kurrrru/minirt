/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:27:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 21:21:49 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	key_hook_update_element(int keycode, t_data *data);

// return 1 if there is any update
int	key_hook_update(int keycode, t_data *data)
{
	if (data->hook.elem == HOOK_ELEM_NONE)
		return (key_hook_update_element(keycode, data));
	else if (data->hook.elem == HOOK_ELEM_OBJECT)
		return (key_hook_update_object(keycode, data));
	else if (data->hook.elem == HOOK_ELEM_LIGHT)
		return (key_hook_update_light(keycode, data));
	else if (data->hook.elem == HOOK_ELEM_CAMERA)
		return (key_hook_update_camera(keycode, data));
	return (0);
}

static int	key_hook_update_element(int keycode, t_data *data)
{
	if (keycode == M_ELEM_OBJ)
		data->hook.elem = HOOK_ELEM_OBJECT;
	else if (keycode == M_ELEM_LIGHT)
		data->hook.elem = HOOK_ELEM_LIGHT;
	else if (keycode == M_ELEM_CAMERA)
		data->hook.elem = HOOK_ELEM_CAMERA;
	else
		return (0);
	return (1);
}

