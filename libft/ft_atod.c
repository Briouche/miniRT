/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:09:44 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/28 13:11:28 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

// res_frac[0]: total double
// res_frac[1]: frac part of double
// res_frac[2]: used to keep track of decimal level
// state[0]: leading zero?
// state[1]: is frac part?
// state[2]: nbr of significant digits
// state[3]: exponent
static void	init_vars(double *res_frac, int *state)
{
	res_frac[0] = 0.0;
	res_frac[1] = 0.0;
	res_frac[2] = 1.0;
	state[0] = 1;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
}

static double	apply_exponent(double res, int exponent, int sign)
{
	while (exponent-- > 0)
		res *= 10.0;
	res *= sign;
	if (res != 0.0 && fabs(res) < 2.2250738585072014e-308)
		return (0.0);
	return (res);
}

double	ft_atod(const char *s)
{
	double	res_frac[3];
	int		state[5];

	state[4] = parse_sign(&s);
	init_vars(res_frac, state);
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			if (!state[1])
				process_integer(*s, &res_frac[0], state);
			else
				process_fraction(*s, &res_frac[1], &res_frac[2], state);
		}
		if (*s++ == '.' && !state[1])
			state[1] = 1;
	}
	res_frac[0] += (res_frac[1] / res_frac[2]);
	if (state[2] + state[3] > 308)
	{
		if (state[4] > 0)
			return (INFINITY);
		return (-INFINITY);
	}
	return (apply_exponent(res_frac[0], state[3], state[4]));
}
