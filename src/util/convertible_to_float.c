/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertible_to_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:29:14 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/11 21:42:01 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/util.h"

static int	ft_isspace(int c);

bool	convertible_to_float(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (false);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (true);
	if (*str != '.')
		return (false);
	str++;
	if (!ft_isdigit(*str))
		return (false);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (false);
	return (true);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", convertible_to_float("123.456"));
// 	printf("%d\n", convertible_to_float("-123.456"));
// 	printf("%d\n", convertible_to_float("123"));
// 	printf("%d\n", convertible_to_float("-123.456.789"));
// 	printf("%d\n", convertible_to_float("a"));
// 	printf("%d\n", convertible_to_float("123a"));
// 	printf("%d\n", convertible_to_float("123."));
// 	printf("%d\n", convertible_to_float(".123"));
// 	printf("%d\n", convertible_to_float("123.456.789"));
// 	printf("%d\n", convertible_to_float("123.456 "));
// 	printf("%d\n", convertible_to_float(" 123.456"));
// 	printf("%d\n", convertible_to_float(" 123 .456"));
// }
