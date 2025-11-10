/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:01:57 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:29 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_minus(const t_vector *a, const t_vector *b)
{
	return ((t_vector){a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w});
}
