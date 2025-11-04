/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:25:26 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/04 14:44:56 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

int	is_equal_matrix(t_matrix *a, t_matrix *b)
{
	(void)a;
	(void)b;
	return (is_equal(&a->c1, &b->c1));
}
