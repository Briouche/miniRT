/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:32:10 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:32:22 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	matrices_add(const t_matrix *a, const t_matrix *b)
{
	return ((t_matrix){
		(t_vector){a->c1.x + b->c1.x, a->c1.y + b->c1.y,
		a->c1.z + b->c1.z, a->c1.w + b->c1.w,},
		(t_vector){a->c2.x + b->c2.x, a->c2.y + b->c2.y,
		a->c2.z + b->c2.z, a->c2.w + b->c2.w,},
		(t_vector){a->c3.x + b->c3.x, a->c3.y + b->c3.y,
		a->c3.z + b->c3.z, a->c3.w + b->c3.w,},
		(t_vector){a->c4.x + b->c4.x, a->c4.y + b->c4.y,
		a->c4.z + b->c4.z, a->c4.w + b->c4.w,},
	});
}
