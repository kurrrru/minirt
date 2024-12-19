/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:27:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 19:31:47 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	key_hook_update_element(int keycode, t_data *data);

void	key_hook_update(int keycode, t_data *data)
{
	if (data->hook.elem == HOOK_ELEM_NONE)
		key_hook_update_element(keycode, data);
	else if (data->hook.elem == HOOK_ELEM_OBJECT)
		key_hook_update_object(keycode, data);
	else if (data->hook.elem == HOOK_ELEM_LIGHT)
		key_hook_update_light(keycode, data);
	else if (data->hook.elem == HOOK_ELEM_CAMERA)
		key_hook_update_camera(keycode, data);
}

static void	key_hook_update_element(int keycode, t_data *data)
{
	if (keycode == M_ELEM_OBJ)
		data->hook.elem = HOOK_ELEM_OBJECT;
	else if (keycode == M_ELEM_LIGHT)
		data->hook.elem = HOOK_ELEM_LIGHT;
	else if (keycode == M_ELEM_CAMERA)
		data->hook.elem = HOOK_ELEM_CAMERA;
}

