/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:02:37 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/13 18:02:27 by marimiyahar      ###   ########.fr       */
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
