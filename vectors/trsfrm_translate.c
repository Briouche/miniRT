/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trsfrm_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:24:37 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:34:11 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	trsfrm_translate(const double x, const double y, const double z)
{
	return ((t_matrix){{1, 0, 0, 0}, {0, 1, 0, 0},
		{0, 0, 1, 0}, {x, y, z, 1}});
}
