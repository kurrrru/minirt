/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:20:53 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 22:44:32 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "include.h"
# include "macro.h"
# include "struct.h"

double	ft_atof(const char *str);
bool	convertible_to_float(const char *str);
int		msg_exit(char *msg);
void	free_ptrarr(void **arr);

#endif
