/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:35:23 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/04 10:16:39 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	matrix_transpose(t_matrix *m)
{
	return ((t_matrix){
		(t_vector){m->c1.x, m->c2.x, m->c3.x, m->c4.x},
		(t_vector){m->c1.y, m->c2.y, m->c3.y, m->c4.y},
		(t_vector){m->c1.z, m->c2.z, m->c3.z, m->c4.z},
		(t_vector){m->c1.w, m->c2.w, m->c3.w, m->c4.w}
	});
}
