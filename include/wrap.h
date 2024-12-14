/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:04:46 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/14 18:50:03 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAP_H
# define WRAP_H

# include "include.h"
# include "macro.h"

void	*xmalloc(size_t size);
void	*xcalloc(size_t count, size_t size);
void	*xrealloc(void *ptr, size_t old_size, size_t new_size);

void	*xmlx_init(void);
void	*xmlx_new_window(void *mlx_ptr, int width, int height, char *title);
void	*xmlx_new_image(void *mlx_ptr, int width, int height);

int		xopen(const char *pathname, int flags);
void	xclose(int fd);

t_list	*xlstnew(void *content);
char	**xsplit(char const *s, char c);

#endif
