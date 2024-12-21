/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_update_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:49:30 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 22:22:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	key_hook_update_light(int keycode, t_data *data)
{
	if (data->hook.light == HOOK_LIGHT_NONE)
	{
		if (keycode == M_LIGHT_MOVE)
			data->hook.light = HOOK_LIGHT_MOVE;
		else if (keycode == M_BACK)
			data->hook.elem = HOOK_ELEM_NONE;
		else
			return (0);
		return (1);
	}
	if (data->hook.light == HOOK_LIGHT_MOVE)
		return (key_hook_update_light_move(keycode, data));
	return (0);
}
