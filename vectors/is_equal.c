/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:34:28 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 15:40:27 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

int	is_equal(t_vector *a, t_vector *b)
{
	return (fabs(a->x - b->x) < __DBL_EPSILON__
		&& fabs(a->y - b->y) < __DBL_EPSILON__
		&& fabs(a->z - b->z) < __DBL_EPSILON__
		&& fabs(a->w - b->w) < __DBL_EPSILON__);
}
