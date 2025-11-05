/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:02:09 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/04 12:39:36 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	matrix_cofactor(t_matrix *m, int r, int c, int d)
{
	double	minor;

	minor = matrix_minor(m, r, c, d);
	if ((r + c) % 2)
		return (-minor);
	return (minor);
}
