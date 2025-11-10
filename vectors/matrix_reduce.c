/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_reduce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:24:01 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:32:54 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

static inline t_vector	shift_vector_up(const t_vector v, const int r)
{
	if (r == 0)
		return ((t_vector){v.y, v.z, v.w, 0});
	else if (r == 1)
		return ((t_vector){v.x, v.z, v.w, 0});
	else if (r == 2)
		return ((t_vector){v.x, v.y, v.w, 0});
	else
		return ((t_vector){v.x, v.y, v.z, 0});
}

t_matrix	matrix_reduce(const t_matrix *m, const int r, const int c)
{
	t_matrix		sub;
	const t_vector	*cols[4];

	cols[0] = &m->c1;
	cols[1] = &m->c2;
	cols[2] = &m->c3;
	cols[3] = &m->c4;
	sub.c1 = shift_vector_up(*cols[0 + (0 >= c)], r);
	sub.c2 = shift_vector_up(*cols[1 + (1 >= c)], r);
	sub.c3 = shift_vector_up(*cols[2 + (2 >= c)], r);
	return (sub);
}
