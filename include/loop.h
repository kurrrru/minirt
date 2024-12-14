/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:24:11 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 14:10:51 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "include.h"
# include "macro.h"
# include "struct.h"
# include "util.h"

int		key_press(int keycode, t_data *data);
int		main_loop(t_data *data);
void	init_data(t_data *data);
int		close_window(void *param);

#endif
