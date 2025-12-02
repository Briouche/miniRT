/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:04:42 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/28 13:12:14 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse_sign(const char **s)
{
	int	sign;

	sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

void	process_integer(const char c, double *res, int *state)
{
	if (c != '0')
		state[0] = 0;
	if (!state[0])
	{
		state[2]++;
		if (state[2] <= MAX_SIGNIFICANT_DIGITS)
			*res = *res * 10.0 + (c - '0');
		else
			state[3]++;
	}
	else
		*res = *res * 10.0 + (c - '0');
}

void	process_fraction(const char c, double *frac_part,
		double *frac_div, int *state)
{
	if (state[2] < MAX_SIGNIFICANT_DIGITS)
	{
		*frac_div *= 10.0;
		*frac_part = *frac_part * 10.0 + (c - '0');
		if ((c - '0') != 0 || *frac_part != 0.0)
			state[2]++;
	}
}
