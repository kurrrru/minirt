/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:05:48 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 18:55:11 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	prompt(t_data *data)
{
	if (data->hook.elem == HOOK_ELEM_NONE)
		return (prompt_elem(data));
	if (data->hook.elem == HOOK_ELEM_OBJECT)
		return (prompt_object(data));
	if (data->hook.elem == HOOK_ELEM_LIGHT)
		return (prompt_light(data));
	if (data->hook.elem == HOOK_ELEM_CAMERA)
		return (prompt_camera(data));
}
