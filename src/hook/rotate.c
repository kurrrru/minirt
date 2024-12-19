/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:14:12 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 20:22:27 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_vec	vec_multiply_matrix(t_vec vec, double matrix[3][3]);

t_vec	rotate_x(t_vec vec, double angle)
{
	double	rad;

	rad = angle * M_PI / 180;
	return (vec_multiply_matrix(vec, (double [3][3]){
		{1, 0, 0},
		{0, cos(rad), -sin(rad)},
		{0, sin(rad), cos(rad)}}
	));
}

t_vec	rotate_y(t_vec vec, double angle)
{
	double	rad;

	rad = angle * M_PI / 180;
	return (vec_multiply_matrix(vec, (double [3][3]){
		{cos(rad), 0, sin(rad)},
		{0, 1, 0},
		{-sin(rad), 0, cos(rad)}}
	));
}

t_vec	rotate_z(t_vec vec, double angle)
{
	double	rad;

	rad = angle * M_PI / 180;
	return (vec_multiply_matrix(vec, (double [3][3]){
		{cos(rad), -sin(rad), 0},
		{sin(rad), cos(rad), 0},
		{0, 0, 1}}
	));
}

static t_vec	vec_multiply_matrix(t_vec vec, double matrix[3][3])
{
	t_vec	result;

	result.x = vec.x * matrix[0][0]
		+ vec.y * matrix[0][1] + vec.z * matrix[0][2];
	result.y = vec.x * matrix[1][0]
		+ vec.y * matrix[1][1] + vec.z * matrix[1][2];
	result.z = vec.x * matrix[2][0]
		+ vec.y * matrix[2][1] + vec.z * matrix[2][2];
	return (result);
}
