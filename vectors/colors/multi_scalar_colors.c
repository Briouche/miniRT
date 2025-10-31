/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_scalar_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:12:50 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 12:14:31 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_vector	multi_scalar_colors(t_vector *a, double *n)
{
	return (op_multi(a, n));
}