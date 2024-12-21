/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_camera.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:49:06 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 13:32:32 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	key_hook_update_camera(int keycode, t_data *data)
{
	if (data->hook.camera == HOOK_CAMERA_NONE)
	{
		if (keycode == M_CAMERA_MOVE)
			data->hook.camera = HOOK_CAMERA_MOVE;
		else if (keycode == M_CAMERA_ROTATE)
			data->hook.camera = HOOK_CAMERA_ROTATE;
		else if (keycode == M_BACK)
			data->hook.elem = HOOK_ELEM_NONE;
		else
			return (0);
		return (1);
	}
	if (data->hook.camera == HOOK_CAMERA_MOVE)
		return (key_hook_update_camera_move(keycode, data));
	else if (data->hook.camera == HOOK_CAMERA_ROTATE)
		return (key_hook_update_camera_rotate(keycode, data));
	return (0);
}
