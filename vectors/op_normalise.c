/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_normalise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:05:41 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/20 15:56:22 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_normalise(const t_vector *v)
{
	const double	norm = op_magnitude(v);

	if (norm == 0)
		return ((t_vector){0, 0, 0, v->w});
	return ((t_vector){v->x / norm, v->y / norm, v->z / norm, v->w});
}
