/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:10:41 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/05 18:26:04 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wrap.h"

// if calloc fails, print error message and exit.
void	*xcalloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
	{
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
