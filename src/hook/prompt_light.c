/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:52:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 18:54:35 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	prompt_light_translate(t_data *data);
static void	prompt_light_rotate(t_data *data);

void	prompt_light(t_data *data)
{
	if (data->hook.light == HOOK_LIGHT_NONE)
	{
		printf("choose the operation to modify the light:\n");
		printf("  - T: Translate\n");
		printf("  - R: Rotate\n");
		printf("  - B: Back to element selection\n");
	}
	else if (data->hook.light == HOOK_LIGHT_MOVE)
		prompt_light_translate(data);
	else if (data->hook.light == HOOK_LIGHT_ROTATE)
		prompt_light_rotate(data);
}

static void	prompt_light_translate(t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
	{
		printf("choose the axis to move the light:\n");
		printf("  - X: X-axis\n");
		printf("  - Y: Y-axis\n");
		printf("  - Z: Z-axis\n");
		printf("  - B: Back to operation selection\n");
	}
	else
	{
		printf("move the light along the axis:\n");
		printf("  - U: Up\n");
		printf("  - D: Down\n");
		printf("  - B: Back to axis selection\n");
	}
}

static void	prompt_light_rotate(t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
	{
		printf("choose the axis to rotate the light:\n");
		printf("  - X: X-axis\n");
		printf("  - Y: Y-axis\n");
		printf("  - Z: Z-axis\n");
		printf("  - B: Back to operation selection\n");
	}
	else
	{
		printf("rotate the light along the axis:\n");
		printf("  - U: Up\n");
		printf("  - D: Down\n");
		printf("  - B: Back to axis selection\n");
	}
}
