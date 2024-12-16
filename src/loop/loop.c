/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:13 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/15 21:20:37 by marimiyahar      ###   ########.fr       */
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

void	init_data(t_data *data)
{
	data->ambient = (t_color){-1, -1, -1};
	data->camera.fov = -1.0;
	data->light.intensity = -1.0;
	data->objects = NULL;
	data->img.width = 1000;
    data->img.height = 1000;
    data->img.image = NULL;
    data->img.address = NULL;
    data->img.bpp = 0;
    data->img.endian = 0;
}
