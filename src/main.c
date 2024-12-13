/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:30:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 20:11:23 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	is_valid_extension(char **argv);

int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc != 2)
		msg_exit("Invalid number of argument");
	if (is_valid_extension(argv))
		msg_exit("Argument must end with .rt");
	if(init_data(&data) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, CLOSE_EVENT, 0, close_window, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}

static int	is_valid_extension(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (len < 3)
		return (FAILURE);
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3) != 0)
		return (FAILURE);
	return (SUCCESS);
}
