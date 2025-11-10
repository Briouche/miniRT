/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_multi_scalar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:52:09 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:33 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_multi_scalar(const t_vector *v, const double n)
{
	return ((t_vector){v->x * n, v->y * n, v->z * n, v->w});
}
