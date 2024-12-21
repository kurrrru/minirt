/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:29:31 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 19:23:34 by nkawaguc         ###   ########.fr       */
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

typedef enum e_hook_elem
{
	HOOK_ELEM_NONE,
	HOOK_ELEM_OBJECT,
	HOOK_ELEM_LIGHT,
	HOOK_ELEM_CAMERA
}					t_hook_elem;

typedef enum e_hook_obj
{
	HOOK_OBJ_NONE,
	HOOK_OBJ_RESIZE,
	HOOK_OBJ_MOVE,
	HOOK_OBJ_ROTATE
}					t_hook_obj;

typedef enum e_hook_resize
{
	HOOK_RESIZE_NONE,
	HOOK_RESIZE_DIAMETER,
	HOOK_RESIZE_WIDTH,
	HOOK_RESIZE_HEIGHT
}					t_hook_resize;

typedef enum e_hook_light
{
	HOOK_LIGHT_NONE,
	HOOK_LIGHT_MOVE,
	HOOK_LIGHT_ROTATE
}					t_hook_light;

typedef enum e_hook_camera
{
	HOOK_CAMERA_NONE,
	HOOK_CAMERA_MOVE,
	HOOK_CAMERA_ROTATE
}					t_hook_camera;

typedef enum e_hook_axis
{
	HOOK_AXIS_NONE,
	HOOK_AXIS_X,
	HOOK_AXIS_Y,
	HOOK_AXIS_Z
}					t_hook_axis;

typedef enum e_hook_diff
{
	HOOK_DIFF_NONE,
	HOOK_DIFF_UP,
	HOOK_DIFF_DOWN,
}					t_hook_diff;

typedef struct s_hook
{
	t_hook_elem		elem;
	int				idx_displayed;
	int				idx_selected;
	t_hook_obj		obj;
	t_hook_light	light;
	t_hook_camera	camera;
	t_hook_resize	resize;
	t_hook_axis		axis;
	t_hook_diff		rotate;
}				t_hook;

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
	t_hook			hook;
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
