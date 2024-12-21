/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:03:42 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/21 13:48:07 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# include "keymacro.h"

# define CLOSE_EVENT 17
# define SCREEN_WID 800
# define SCREEN_HEI 600

# define SUCCESS 0
# define FAILURE 1

# define M_ELEM_OBJ KEY_O
# define M_ELEM_LIGHT KEY_L
# define M_ELEM_CAMERA KEY_C

# define M_BACK KEY_B

# define M_OBJ_NEXT KEY_N
# define M_OBJ_THIS KEY_T
# define M_OBJ_PREV KEY_P

# define M_OBJ_RESIZE KEY_Z
# define M_OBJ_MOVE KEY_T
# define M_OBJ_ROTATE KEY_R

# define M_RESIZE_DIAMETER KEY_D
# define M_RESIZE_WIDTH KEY_W
# define M_RESIZE_HEIGHT KEY_H

# define M_LIGHT_MOVE KEY_T
# define M_LIGHT_ROTATE KEY_R

# define M_CAMERA_MOVE KEY_T
# define M_CAMERA_ROTATE KEY_R

# define M_AXIS_X KEY_X
# define M_AXIS_Y KEY_Y
# define M_AXIS_Z KEY_Z

# define M_AXIS_UP KEY_U
# define M_AXIS_DOWN KEY_D

# define M_RESIZE_UP KEY_U
# define M_RESIZE_DOWN KEY_D

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

#endif
