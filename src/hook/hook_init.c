/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:02:46 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 20:01:02 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	hook_init(t_hook *hook)
{
	hook->elem = HOOK_ELEM_NONE;
	hook->obj = HOOK_OBJ_NONE;
	hook->light = HOOK_LIGHT_NONE;
	hook->camera = HOOK_CAMERA_NONE;
	hook->resize = HOOK_RESIZE_NONE;
	hook->axis = HOOK_AXIS_NONE;
	hook->rotate = HOOK_DIFF_NONE;
	hook->idx_displayed = 0;
	hook->idx_selected = -1;
}