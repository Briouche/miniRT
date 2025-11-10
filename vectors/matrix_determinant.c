/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:07:15 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:32:36 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	matrix_determinant(const t_matrix *m, const int d)
{
	double		det;

	det = m->c1.x * matrix_cofactor(m, 0, 0, d);
	det += m->c1.y * matrix_cofactor(m, 1, 0, d);
	det += m->c1.z * matrix_cofactor(m, 2, 0, d);
	det += (d == 4) * m->c1.w * matrix_cofactor(m, 3, 0, d);
	return (det);
}
