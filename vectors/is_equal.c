/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:34:28 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/10 13:20:27 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

int	is_equal(const t_vector *a, const t_vector *b)
{
	return (fabs(a->x - b->x) < EPSILON
		&& fabs(a->y - b->y) < EPSILON
		&& fabs(a->z - b->z) < EPSILON
		&& fabs(a->w - b->w) < EPSILON);
}
