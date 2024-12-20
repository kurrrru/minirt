/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:49:01 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 13:44:19 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	prompt_camera_translate(t_data *data);
static void	prompt_camera_rotate(t_data *data);

void	prompt_camera(t_data *data)
{
	if (data->hook.camera == HOOK_CAMERA_NONE)
	{
		printf("choose the operation to modify the camera:\n");
		printf("  - T: Translate\n");
		printf("  - R: Rotate\n");
		printf("  - B: Back to element selection\n");
	}
	else if (data->hook.camera == HOOK_CAMERA_MOVE)
		prompt_camera_translate(data);
	else if (data->hook.camera == HOOK_CAMERA_ROTATE)
		prompt_camera_rotate(data);
}

static void	prompt_camera_translate(t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
	{
		printf("choose the axis to move the camera:\n");
		printf("  - X: X-axis\n");
		printf("  - Y: Y-axis\n");
		printf("  - Z: Z-axis\n");
		printf("  - B: Back to operation selection\n");
	}
	else
	{
		printf("move the camera along the axis:\n");
		printf("  - U: Up\n");
		printf("  - D: Down\n");
		printf("  - B: Back to axis selection\n");
	}
}

static void	prompt_camera_rotate(t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
	{
		printf("choose the axis to rotate the camera:\n");
		printf("  - X: X-axis\n");
		printf("  - Y: Y-axis\n");
		printf("  - Z: Z-axis\n");
		printf("  - B: Back to operation selection\n");
	}
	else
	{
		printf("rotate the camera along the axis:\n");
		printf("  - U: Up\n");
		printf("  - D: Down\n");
		printf("  - B: Back to axis selection\n");
	}
}
