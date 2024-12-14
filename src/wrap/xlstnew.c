/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlstnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:46:33 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 18:51:08 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wrap.h"

t_list	*xlstnew(void *content)
{
	t_list	*ret;

	ret = ft_lstnew(content);
	if (!ret)
	{
		perror("lstnew");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
