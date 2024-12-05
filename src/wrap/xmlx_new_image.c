/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlx_new_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:17:09 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/05 18:27:11 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wrap.h"

void	*xmlx_new_image(void *mlx_ptr, int width, int height)
{
	void	*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img_ptr == NULL)
	{
		perror("mlx_new_image");
		exit(EXIT_FAILURE);
	}
	return (img_ptr);
}
