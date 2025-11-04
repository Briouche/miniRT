/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector_multi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:42:46 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/04 10:16:44 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	matrix_vector_multi(t_matrix *m, t_vector *v)
{
	return ((t_vector){
		v->x * m->c1.x + v->y * m->c2.x + v->z * m->c3.x + v->z * m->c4.x,
		v->x * m->c1.y + v->y * m->c2.y + v->z * m->c3.y + v->z * m->c1.y,
		v->x * m->c1.z + v->y * m->c2.z + v->z * m->c3.z + v->z * m->c2.z,
		v->x * m->c1.w + v->y * m->c2.w + v->z * m->c3.w + v->z * m->c2.w
	});
}
