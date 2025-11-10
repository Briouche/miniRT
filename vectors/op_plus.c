/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:06:38 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:43 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_plus(const t_vector *a, const t_vector *b)
{
	return ((t_vector){a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w});
}
