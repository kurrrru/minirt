/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:42:57 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 18:05:19 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	prompt_object_display(t_data *data);
static void	prompt_object_resize(t_data *data);
static void	prompt_object_translate(t_data *data);
static void	prompt_object_rotate(t_data *data);

void	prompt_object(t_data *data)
{
	if (data->hook.idx_selected == -1)
	{
		printf("choose the object to modify the parameter:\n");
		prompt_object_display(data);
		printf("  - N: Next object\n");
		printf("  - T: This object\n");
		printf("  - P: Previous object\n");
		printf("  - B: Back to element selection\n");
	}
	else if (data->hook.obj == HOOK_OBJ_NONE)
	{
		printf("choose the operation to modify the object:\n");
		printf("  - Z: Resize\n");
		printf("  - T: Translate\n");
		printf("  - R: Rotate\n");
		printf("  - B: Back to object selection\n");
	}
	else if (data->hook.obj == HOOK_OBJ_RESIZE)
		prompt_object_resize(data);
	else if (data->hook.obj == HOOK_OBJ_MOVE)
		prompt_object_translate(data);
	else if (data->hook.obj == HOOK_OBJ_ROTATE)
		prompt_object_rotate(data);
}

static void	prompt_object_display(t_data *data)
{
	t_object	*object;

	printf("=== now selected object ===\n");
	object = hook_lst_at(data, data->hook.idx_displayed);
	printf(" id: %d\n", data->hook.idx_displayed);
	if (object->shape == PLANE)
		printf(" type: Plane\n");
	else
	{
		if (object->shape == SPHERE)
			printf(" type: Sphere\n");
		else if (object->shape == CYLINDER)
			printf(" type: Cylinder\n");
		printf(" center: (%f, %f, %f)\n",
			object->center.x, object->center.y, object->center.z);
		if (object->shape == SPHERE)
			printf(" diameter: %f\n", object->radius * 2);
		else if (object->shape == CYLINDER)
		{
			printf(" width: %f\n", object->radius * 2);
			printf(" height: %f\n", object->height);
		}
	}
	printf("===========================\n");
}

static void	prompt_object_resize(t_data *data)
{
	if (data->hook.resize == HOOK_RESIZE_NONE)
	{
		printf("choose the property to resize:\n");
		if (hook_lst_at(data, data->hook.idx_selected)->shape == SPHERE)
			printf("  - D: Diameter\n");
		else if (hook_lst_at(data, data->hook.idx_selected)->shape == CYLINDER)
		{
			printf("  - W: Width\n");
			printf("  - H: Height\n");
		}
		printf("  - B: Back to operation selection\n");
	}
	else
	{
		printf("choose the change of the property:\n");
		printf("  - U: Increase\n");
		printf("  - D: Decrease\n");
		printf("  - B: Back to property selection\n");
	}
}

static void	prompt_object_translate(t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
	{
		printf("choose the axis to translate:\n");
		printf("  - X: X-axis\n");
		printf("  - Y: Y-axis\n");
		printf("  - Z: Z-axis\n");
		printf("  - B: Back to operation selection\n");
	}
	else
	{
		printf("choose the direction to translate:\n");
		printf("  - U: Up\n");
		printf("  - D: Down\n");
		printf("  - B: Back to axis selection\n");
	}
}

static void	prompt_object_rotate(t_data *data)
{
	if (data->hook.axis == HOOK_AXIS_NONE)
	{
		printf("choose the axis to rotate:\n");
		printf("  - X: X-axis\n");
		printf("  - Y: Y-axis\n");
		printf("  - Z: Z-axis\n");
		printf("  - B: Back to operation selection\n");
	}
	else
	{
		printf("choose the direction to rotate:\n");
		printf("  - U: Up\n");
		printf("  - D: Down\n");
		printf("  - B: Back to axis selection\n");
	}
}
