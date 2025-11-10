/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_scalar_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:12:50 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:14 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	multi_scalar_colors(const t_vector *a, const double n)
{
	return ((t_vector){a->x * n, a->w * n, a->z * n, 0});
}
