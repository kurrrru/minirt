/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_lst_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:57:50 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 19:58:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_object	*hook_lst_at(t_data *data, int idx)
{
	t_list	*objects;
	int		i;

	objects = data->objects;
	i = 0;
	while (objects && i < idx)
	{
		objects = objects->next;
		i++;
	}
	if (objects)
		return ((t_object *)objects->content);
	return (NULL);
}
