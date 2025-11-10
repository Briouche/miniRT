/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:11:50 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:53 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	sub_colors(const t_vector *a, const t_vector *b)
{
	return ((t_vector){a->x - b->x, a->y - b->y, a->z - b->z, 0});
}
