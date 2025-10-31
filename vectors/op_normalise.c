/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_normalise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:05:41 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 10:48:41 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_normalise(t_vector *v)
{
	double	norm;

	norm = op_magnitude(v);
	return ((t_vector){v->x / norm, v->y / norm, v->z / norm, v->w});
}
