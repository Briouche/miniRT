/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:31:48 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/06 14:38:36 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;
	int	res;

	n = 0;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == ' ')
		n++;
	sign = 1;
	if (str[n] == '+' || str[n] == '-')
	{
		if (str[n] == '-')
			sign = -1;
		n++;
	}
	res = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		res *= 10;
		res += str[n] - 48;
		n++;
	}
	return (sign * res);
}
