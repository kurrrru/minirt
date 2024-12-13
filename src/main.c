/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:30:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 15:28:40 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	check_argv(char **argv);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (msg_exit("Invalid number of argument", EXIT_FAILURE));
	if (!check_argv(argv))
		return (msg_exit("Argument must end with .rt", EXIT_FAILURE));
	return (0);
}

static int	check_argv(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (len < 3)
		return (0);
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3) != 0)
		return (0);
	return (1);
}
