/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:48:45 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/19 19:26:58 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
設定するhook
そもそも使えるkey: small alphabet, number
- 物体の大きさ
	- 球の直径: key 7/8 (also 9/0)
	- 円柱
		- 直径: key 7/8
		- 高さ: key 9/0
- 物体の位置
	- x+/x-: 1/2
	- y+/y-: 3/4
	- z+/z-: 5/6
- 光源の位置
	- x+/x-: q/w
	- y+/y-: e/r
	- z+/z-: t/y

*/


int	key_hook_loop(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	key_hook_update(keycode, data);
	prompt(data);
	return (0);
}
