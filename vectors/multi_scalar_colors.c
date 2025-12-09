/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_scalar_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:12:50 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/09 18:25:21 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	multi_scalar_colors(const t_vector *a, const double n)
{
	return ((t_vector){a->x * n, a->y * n, a->z * n, 0});
}
