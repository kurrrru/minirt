/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:26:05 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/13 23:33:50 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "include.h"
# include "macro.h"
# include "struct.h"
# include "util.h"

int		read_file(t_data *data, char **argv);

// utilities
t_vec	parse_vec(char *str);
t_color	parse_color(char *str);

// set elements
int		set_ambient(t_data *data, char **params);
int		set_camera(t_data *data, char **params);
int		set_light(t_data *data, char **params);

// set objects
int		set_cylinder(t_data *data, char **params);
int		set_plane(t_data *data, char **params);
int		set_sphere(t_data *data, char **params);

#endif