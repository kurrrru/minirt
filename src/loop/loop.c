/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:13 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/13 23:59:21 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/loop.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

int	main_loop(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	return (0);
}

int	init_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (msg_exit("Failed to initialize mlx\n"));
	data->ambient = (t_color){-1, -1, -1};
	data->camera.fov = -1.0;
	data->light.intensity = -1.0;
	data->objects = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (msg_exit("Failed to initialize mlx\n"));
	data->win = mlx_new_window(data->mlx, 1000, 1000, "miniRT");
	if (!data->win)
		return (msg_exit("Failed to create window\n"));
	return (EXIT_SUCCESS);
}
