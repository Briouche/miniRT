/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_perpendicular_comp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:06:15 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:15 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	op_perpendicular_comp(t_vector *v, t_vector *axis)
{
	t_vector	proj;

	proj = op_multi_scalar(axis, op_dot(v, axis));
	return (op_minus(v, &proj));
}
