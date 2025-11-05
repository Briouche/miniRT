/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trsfrm_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:24:40 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 16:59:08 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	trsfrm_rotate_x(double *angle)
{
	return ((t_matrix){{1, 0, 0, 0}, {0, cos(*angle), sin(*angle), 0},
		{0, -sin(*angle), cos(*angle), 0}, {0, 0, 0, 1}});
}

t_matrix	trsfrm_rotate_y(double *angle)
{
	return ((t_matrix){{cos(*angle), 0, -sin(*angle), 0}, {0, 1, 0, 0},
		{sin(*angle), 0, cos(*angle), 0}, {0, 0, 0, 1}});
}

t_matrix	trsfrm_rotate_z(double *angle)
{
	return ((t_matrix){{cos(*angle), sin(*angle), 0, 0},
		{-sin(*angle), cos(*angle), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});
}
