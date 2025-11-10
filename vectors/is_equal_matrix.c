/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:25:26 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:32:09 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

int	is_equal_matrix(const t_matrix *a, const t_matrix *b)
{
	return (is_equal(&a->c1, &b->c1)
		&& is_equal(&a->c2, &b->c2)
		&& is_equal(&a->c3, &a->c3)
		&& is_equal(&a->c4, &b->c4));
}
