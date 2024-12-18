/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:29:31 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/17 01:03:27 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "include.h"
# include "macro.h"

typedef struct s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct s_image
{
	void			*image;
	char			*address;
	int				bpp;
	int				endian;
	int				width;
	int				height;
	int				line_size;
}					t_image;

typedef enum e_shape
{
	PLANE,
	SPHERE,
	CYLINDER
}					t_shape;

typedef struct s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct s_object
{
	enum e_shape	shape;
	t_vec			center;
	t_vec			norm_vector;
	double			radius;
	double			height;
	t_color			color;
}					t_object;

typedef struct s_light
{
	t_vec			position;
	t_color			color;
	double			intensity;
}					t_light;

typedef struct s_camera
{
	t_vec			position;
	t_vec			orientation;
	double			fov;
}					t_camera;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_camera		camera;
	t_list			*objects;
	t_color			ambient;
	t_light			light;
}					t_data;

typedef struct s_closest_obj
{
	t_object		*closest_obj;
	double			min_dist;
	t_color			final_color;
	t_vec			intersection_point;
	t_vec			normal;
}					t_closest_obj;

typedef struct s_basis
{
	t_vec			forward;
	t_vec			right;
	t_vec			up;
}					t_basis;

#endif
