/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:34:28 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/03 13:55:35 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

int	is_equal(const t_vector *a, const t_vector *b)
{
	return (fabs(a->x - b->x) < 0.001
		&& fabs(a->y - b->y) < 0.001
		&& fabs(a->z - b->z) < 0.001
		&& fabs(a->w - b->w) < 0.001);
}
