/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:19:45 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/14 18:39:18 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wrap.h"

// if split fails, print error message and exit
char	**xsplit(char const *s, char c)
{
	char	**split;

	split = ft_split(s, c);
	if (split == NULL)
	{
		perror("split");
		exit(EXIT_FAILURE);
	}
	return (split);
}
