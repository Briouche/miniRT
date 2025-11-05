/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector_multi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:42:46 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 12:44:13 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	matrix_vector_multi(t_matrix *m, t_vector *v)
{
	return ((t_vector){
		v->x * m->c1.x + v->y * m->c2.x + v->z * m->c3.x + v->w * m->c4.x,
		v->x * m->c1.y + v->y * m->c2.y + v->z * m->c3.y + v->w * m->c4.y,
		v->x * m->c1.z + v->y * m->c2.z + v->z * m->c3.z + v->w * m->c4.z,
		v->x * m->c1.w + v->y * m->c2.w + v->z * m->c3.w + v->w * m->c4.w
	});
}
