/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:07:15 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/04 12:39:40 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	matrix_determinant(t_matrix *m, int d)
{
	double		det;

	det = m->c1.x * matrix_cofactor(m, 0, 0, d);
	det += m->c1.y * matrix_cofactor(m, 1, 0, d);
	det += m->c1.z * matrix_cofactor(m, 2, 0, d);
	det += (d == 4) * m->c1.w * matrix_cofactor(m, 3, 0, d);
	return (det);
}
