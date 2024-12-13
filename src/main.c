/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:30:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 17:48:36 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	is_valid_extension(char **argv);

int	main(int argc, char **argv)
{
	if (argc != 2)
		msg_exit("Invalid number of argument");
	if (is_valid_extension(argv))
		msg_exit("Argument must end with .rt");
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
