/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_magnitude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:55:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:26 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	op_magnitude(const t_vector *v)
{
	const double	x = v->x;
	const double	y = v->y;
	const double	z = v->z;

	return (sqrt(x * x + y * y + z * z));
}
