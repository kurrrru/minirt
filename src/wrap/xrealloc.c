/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:09:34 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/05 18:27:11 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wrap.h"

// if realloc fails, print error message and exit
// [Important Notes]: ptr will not be freed
void	*xrealloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (old_size > new_size)
	{
		ft_putendl_fd("xrealloc: old_size > new_size", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	new_ptr = xmalloc(new_size);
	ft_bzero(new_ptr, new_size);
	ft_memcpy(new_ptr, ptr, old_size);
	return (new_ptr);
}
