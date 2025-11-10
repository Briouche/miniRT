/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:16:32 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/08 16:20:42 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_ray	ray(t_vector *origin, t_vector *direction)
{
	return ((t_ray){.origin = *origin, .direction = *direction});
}
