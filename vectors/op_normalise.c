/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_normalise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:05:41 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:37 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_normalise(const t_vector *v)
{
	const double	norm = op_magnitude(v);

	return ((t_vector){v->x / norm, v->y / norm, v->z / norm, v->w});
}
