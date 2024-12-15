/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:26:05 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/14 22:10:51 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "include.h"
# include "macro.h"
# include "struct.h"
# include "wrap.h"
# include "util.h"

int		read_file(t_data *data, char **argv);

// utilities
t_vec	parse_vec(char *str);
t_color	parse_color(char *str);
int		array_len(char **array);

// set elements
int		set_ambient(t_data *data, char **params);
int		set_camera(t_data *data, char **params);
int		set_light(t_data *data, char **params);

// set objects
int		set_cylinder(t_data *data, char **params);
int		set_plane(t_data *data, char **params);
int		set_sphere(t_data *data, char **params);

#endif