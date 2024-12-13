/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:29:31 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 17:25:54 by marimiyahar      ###   ########.fr       */
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
}					t_image;

typedef enum e_shape
{
	PLANE,
	SPHERE,
	CYLINDER
} e_shape;

typedef struct s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct s_obejct
{
	enum e_shape	shape;
	t_vec			center;
	t_vec			norm_vector;
	double			radius;
	double			height;
	t_color			color;
}					t_object;

typedef struct s_camera
{
}					t_camera;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_camera		camera;
	t_list			*objects;
	t_color			ambient;
}					t_data;

#endif
