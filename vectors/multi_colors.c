/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:11:20 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/03 13:43:49 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	multi_colors(const t_vector *a, const t_vector *b)
{
	return ((t_vector){a->x * b->x / 255, a->y * b->y / 255, a->z * b->z / 255, 0});
}
