/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:11:20 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:12 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	multi_colors(const t_vector *a, const t_vector *b)
{
	return ((t_vector){a->x * b->x, a->y * b->y, a->z * b->z, 0});
}
