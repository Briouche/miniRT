/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:20:33 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:33:08 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	matrix(const t_vector *a, const t_vector *b,
const t_vector *c, const t_vector *d)
{
	return ((t_matrix){(*a), *b, *c, *d});
}
