/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlx_get_data_addr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:37:25 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 00:59:41 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wrap.h"

char	*xmlx_get_data_addr(void *img_ptr, int *bpp, int *line_size,
		int *endian)
{
	char	*addr;

	addr = mlx_get_data_addr(img_ptr, bpp, line_size, endian);
	if (addr == NULL)
	{
		perror("mlx_get_data_addr");
		exit(EXIT_FAILURE);
	}
	return (addr);
}
