/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:41:43 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/20 13:44:19 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	prompt_elem(t_data *data)
{
	(void)data;
	printf("choose the type of element to modify the parameter:\n");
	printf("  - O: Object\n");
	printf("  - L: Light\n");
	printf("  - C: Camera\n");
}
