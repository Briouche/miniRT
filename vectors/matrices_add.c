/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:32:10 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/03 17:51:10 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	matrices_add(t_matrix *a, t_matrix *b)
{
	return ((t_matrix){
		op_plus(&a->c1, &b->c1),
		op_plus(&a->c2, &b->c2),
		op_plus(&a->c3, &b->c3),
		op_plus(&a->c4, &b->c4)
	});
}
