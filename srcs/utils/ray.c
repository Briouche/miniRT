/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:16:32 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 17:53:00 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_ray	ray(t_vector *origin, t_vector *direction)
{
	return ((t_ray){.origin = *origin, .direction = *direction});
}
