/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_multiply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:54:21 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/03 21:20:26 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	matrices_multiply(t_matrix *a, t_matrix *b)
{
	t_matrix	result;
	t_vector	row[4];

	row[0] = (t_vector){a->c1.x, a->c2.x, a->c3.x, a->c4.x};
	row[1] = (t_vector){a->c1.y, a->c2.y, a->c3.y, a->c4.y};
	row[2] = (t_vector){a->c1.z, a->c2.z, a->c3.z, a->c4.z};
	row[3] = (t_vector){a->c1.w, a->c2.w, a->c3.w, a->c4.w};
	result.c1.x = op_dot(&row[0], &b->c1);
	result.c1.y = op_dot(&row[1], &b->c1);
	result.c1.z = op_dot(&row[2], &b->c1);
	result.c1.w = op_dot(&row[3], &b->c1);
	result.c2.x = op_dot(&row[0], &b->c2);
	result.c2.y = op_dot(&row[1], &b->c2);
	result.c2.z = op_dot(&row[2], &b->c2);
	result.c2.w = op_dot(&row[3], &b->c2);
	result.c3.x = op_dot(&row[0], &b->c3);
	result.c3.y = op_dot(&row[1], &b->c3);
	result.c3.z = op_dot(&row[2], &b->c3);
	result.c3.w = op_dot(&row[3], &b->c3);
	result.c4.x = op_dot(&row[0], &b->c4);
	result.c4.y = op_dot(&row[1], &b->c4);
	result.c4.z = op_dot(&row[2], &b->c4);
	result.c4.w = op_dot(&row[3], &b->c4);
	return (result);
}
