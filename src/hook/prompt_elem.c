/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:41:43 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 23:53:22 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	prompt_elem(t_data *data)
{
	printf("choose the type of element to modify the parameter:\n");
	if (data->objects)
		printf("  - O: Object\n");
	printf("  - L: Light\n");
	printf("  - C: Camera\n");
}
