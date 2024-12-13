/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:13 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/13 17:38:07 by marimiyahar      ###   ########.fr       */
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
	data->mlx = mlx_init();
	data->objects = NULL;
	if (!data->mlx)
		return (printf("Error\n Failed to initialize mlx\n"), EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, 1000, 1000, "miniRT");
	if (!data->win)
		return (printf("Error\nFailed to create window\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
