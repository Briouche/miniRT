/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:22:59 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:37:57 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_vector	position(t_ray *r, double t)
{
	t_vector	tmp;

	tmp = op_multi_scalar(&r->direction, t);
	return (op_plus(&r->origin, &tmp));
}
