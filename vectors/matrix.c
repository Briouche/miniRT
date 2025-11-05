/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:20:33 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/03 20:59:23 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	matrix(t_vector *a, t_vector *b, t_vector *c, t_vector *d)
{
	return ((t_matrix){(*a), *b, *c, *d});
}
