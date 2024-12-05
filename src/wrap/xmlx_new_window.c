/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlx_new_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:15:56 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/05 18:27:11 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wrap.h"


void	*xmlx_new_window(void *mlx_ptr, int width, int height, char *title)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, width, height, title);
	if (win_ptr == NULL)
	{
		perror("mlx_new_window");
		exit(EXIT_FAILURE);
	}
	return (win_ptr);
}
