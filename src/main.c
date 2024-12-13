/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:30:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 17:17:29 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data data;
	
	if(init_data(&data) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, CLOSE_EVENT, 0, close_window, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
