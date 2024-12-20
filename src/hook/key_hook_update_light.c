/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:49:30 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 13:31:08 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	key_hook_update_light(int keycode, t_data *data)
{
	if (data->hook.light == HOOK_LIGHT_NONE)
	{
		if (keycode == M_LIGHT_MOVE)
			data->hook.light = HOOK_LIGHT_MOVE;
		else if (keycode == M_LIGHT_ROTATE)
			data->hook.light = HOOK_LIGHT_ROTATE;
		else if (keycode == M_BACK)
			data->hook.elem = HOOK_ELEM_NONE;
		else
			return (0);
		return (1);
	}
	if (data->hook.light == HOOK_LIGHT_MOVE)
		return (key_hook_update_light_move(keycode, data));
	else if (data->hook.light == HOOK_LIGHT_ROTATE)
		return (key_hook_update_light_rotate(keycode, data));
	return (0);
}
