/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:31:18 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/13 15:29:15 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/util.h"

int	msg_exit(char *msg, int exit_status)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(exit_status);
}
