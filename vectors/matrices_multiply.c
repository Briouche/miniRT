/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_multiply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:54:21 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:32:25 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"


static inline t_vector	vector_scale(const t_vector *v, double s)
{
	return (t_vector){v->x * s, v->y * s, v->z * s, v->w * s};
}

static inline t_vector	vector_add(const t_vector *v1, const t_vector v2)
{
	return (t_vector){v1->x + v2.x, v1->y + v2.y, v1->z + v2.z, v1->w + v2.w};
}

t_matrix matrices_multiply(const t_matrix *a, const t_matrix *b)
{
	t_matrix result;

	result.c1 = vector_scale(&a->c1, b->c1.x);
	result.c1 = vector_add(&result.c1, vector_scale(&a->c2, b->c1.y));
	result.c1 = vector_add(&result.c1, vector_scale(&a->c3, b->c1.z));
	result.c1 = vector_add(&result.c1, vector_scale(&a->c4, b->c1.w));
	result.c2 = vector_scale(&a->c1, b->c2.x);
	result.c2 = vector_add(&result.c2, vector_scale(&a->c2, b->c2.y));
	result.c2 = vector_add(&result.c2, vector_scale(&a->c3, b->c2.z));
	result.c2 = vector_add(&result.c2, vector_scale(&a->c4, b->c2.w));
	result.c3 = vector_scale(&a->c1, b->c3.x);
	result.c3 = vector_add(&result.c3, vector_scale(&a->c2, b->c3.y));
	result.c3 = vector_add(&result.c3, vector_scale(&a->c3, b->c3.z));
	result.c3 = vector_add(&result.c3, vector_scale(&a->c4, b->c3.w));
	result.c4 = vector_scale(&a->c1, b->c4.x);
	result.c4 = vector_add(&result.c4, vector_scale(&a->c2, b->c4.y));
	result.c4 = vector_add(&result.c4, vector_scale(&a->c3, b->c4.z));
	result.c4 = vector_add(&result.c4, vector_scale(&a->c4, b->c4.w));
	return result;
}
