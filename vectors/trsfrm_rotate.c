/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trsfrm_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:24:40 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:34:03 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	trsfrm_rotate_x(const double angle)
{
	const double	c = cos(angle);
	const double	s = sin(angle);

	return ((t_matrix){{1, 0, 0, 0}, {0, c, s, 0},
		{0, -s, c, 0}, {0, 0, 0, 1}});
}

t_matrix	trsfrm_rotate_y(const double angle)
{
	const double	c = cos(angle);
	const double	s = sin(angle);

	return ((t_matrix){{c, 0, -s, 0}, {0, 1, 0, 0},
		{s, 0, c, 0}, {0, 0, 0, 1}});
}

t_matrix	trsfrm_rotate_z(const double angle)
{
	const double	c = cos(angle);
	const double	s = sin(angle);

	return ((t_matrix){{c, s, 0, 0},
		{-s, c, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});
}
