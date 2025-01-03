/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymacro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:19:19 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/21 13:48:24 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMACRO_H
# define KEYMACRO_H

# ifdef __APPLE__

#  define KEY_0  29
#  define KEY_1  18
#  define KEY_2  19
#  define KEY_3  20
#  define KEY_4  21
#  define KEY_5  23
#  define KEY_6  22
#  define KEY_7  26
#  define KEY_8  28
#  define KEY_9  25

#  define KEY_A  0
#  define KEY_B  11
#  define KEY_C  8
#  define KEY_D  2
#  define KEY_E  14
#  define KEY_F  3
#  define KEY_G  5
#  define KEY_H  4
#  define KEY_I  34
#  define KEY_J  38
#  define KEY_K  40
#  define KEY_L  37
#  define KEY_M  46
#  define KEY_N  45
#  define KEY_O  31
#  define KEY_P  35
#  define KEY_Q  12
#  define KEY_R  15
#  define KEY_S  1
#  define KEY_T  17
#  define KEY_U  32
#  define KEY_V  9
#  define KEY_W  13
#  define KEY_X  7
#  define KEY_Y  16
#  define KEY_Z  6

#  define KEY_ARROW_UP    126
#  define KEY_ARROW_DOWN  125
#  define KEY_ARROW_LEFT  123
#  define KEY_ARROW_RIGHT 124

#  define ESC_KEY 53

# else

#  define KEY_0 48
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
#  define KEY_8 56
#  define KEY_9 57

#  define KEY_A 97
#  define KEY_B 98
#  define KEY_C 99
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_F 102
#  define KEY_G 103
#  define KEY_H 104
#  define KEY_I 105
#  define KEY_J 106
#  define KEY_K 107
#  define KEY_L 108
#  define KEY_M 109
#  define KEY_N 110
#  define KEY_O 111
#  define KEY_P 112
#  define KEY_Q 113
#  define KEY_R 114
#  define KEY_S 115
#  define KEY_T 116
#  define KEY_U 117
#  define KEY_V 118
#  define KEY_W 119
#  define KEY_X 120
#  define KEY_Y 121
#  define KEY_Z 122

#  define KEY_ARROW_UP 65362
#  define KEY_ARROW_DOWN 65364
#  define KEY_ARROW_LEFT 65361
#  define KEY_ARROW_RIGHT 65363

#  define ESC_KEY 65307

# endif

#endif
