/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_multi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:52:09 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 10:48:46 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_multi(t_vector *v, double *scalar)
{
	double	n;

	n = *scalar;
	return ((t_vector){v->x * n, v->y * n, v->z * n, v->w});
}
