/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:25:20 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/21 13:39:11 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# ifdef __APPLE__
#  include "../minilibx_opengl/mlx.h"
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
# else
#  include "../minilibx-linux/mlx.h"
#  include "../minilibx-linux/mlx_int.h"
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#endif
