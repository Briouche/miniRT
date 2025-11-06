/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:49:25 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/06 14:50:31 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static double	ft_atod_helper(int i, const char *str)
{
	double	decimal;
	double	result;

	decimal = 1.0;
	result = 0;
	if (!ft_isdigit(str[i]))
		return (-DBL_MAX);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			decimal *= 10;
			result = result + (str[i] - '0') / decimal;
			i++;
		}
	}
	return (result);
}

double	ft_atod(const char *str)
{
	double	result;
	double	sign;
	int		i;

	sign = 1;
	i = 0;
	if (!str)
		return (-DBL_MAX);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_atod_helper(i, str);
	if (result == -DBL_MAX)
		return (-DBL_MAX);
	return (sign * result);
}
