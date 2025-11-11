/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector_multi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:42:46 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/11 14:15:41 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	matrix_vector_multi(const t_matrix *m, const t_vector *v)
{
	const double	x = v->x;
	const double	y = v->y;
	const double	z = v->z;
	const double	w = v->w;

	return ((t_vector){
		x * m->c1.x + y * m->c2.x + z * m->c3.x + w * m->c4.x,
		x * m->c1.y + y * m->c2.y + z * m->c3.y + w * m->c4.y,
		x * m->c1.z + y * m->c2.z + z * m->c3.z + w * m->c4.z,
		x * m->c1.w + y * m->c2.w + z * m->c3.w + w * m->c4.w
	});
}
