/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trsfrm_shear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:55:16 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 15:20:45 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	trsfrm_shear(const t_vector *a, const t_vector *b)
{
	return ((t_matrix){{1, a->z, b->x, 0}, {a->x, 1, b->y, 0},
		{a->y, a->w, 1, 0}, {0, 0, 0, 1}});
}

//USE :
// t_vector a = { yx, zx, xy, zy };
// t_vector b = { xz, yz, 0, 0 };
// with yx --> amount by which to multiply y before adding it to x