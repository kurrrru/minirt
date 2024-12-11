/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:15:51 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/11 21:42:13 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/util.h"

static int	ft_isspace(int c);

double	ft_atof(const char *str)
{
	double	integer;
	double	decimal;
	double	divisor;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	integer = 0;
	while (ft_isdigit(*str))
		integer = integer * 10 + (*str++ - '0') * sign;
	if (*str == '.')
		str++;
	decimal = 0;
	divisor = 1;
	while (ft_isdigit(*str))
	{
		decimal = decimal * 10 + (*str++ - '0') * sign;
		divisor *= 10;
	}
	return (integer + decimal / divisor);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	printf("%f\n", ft_atof("123.456"));
// 	printf("%f\n", atof("123.456"));
// 	printf("%f\n", ft_atof("-123.456"));
// 	printf("%f\n", atof("-123.456"));
// 	printf("%f\n", ft_atof("123"));
// 	printf("%f\n", atof("123"));
// 	printf("%f\n", ft_atof("-123"));
// 	printf("%f\n", atof("-123"));
// 	printf("%f\n", ft_atof("0.456"));
// 	printf("%f\n", atof("0.456"));
// 	printf("%f\n", ft_atof("-0.000456"));
// 	printf("%f\n", atof("-0.000456"));	
// }
