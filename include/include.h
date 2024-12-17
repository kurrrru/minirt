/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:25:20 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/15 20:54:57 by marimiyahar      ###   ########.fr       */
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
