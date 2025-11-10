/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trsfrm_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:15:41 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:34:06 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	trsfrm_scale(const double x, const double y, const double z)
{
	return ((t_matrix){{x, 0, 0, 0}, {0, y, 0, 0},
		{0, 0, z, 0}, {0, 0, 0, 1}});
}
