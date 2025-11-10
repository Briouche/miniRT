/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:37:24 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/08 16:39:12 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_sphere	sphere(t_vector *center, t_vector *radius)
{
	return ((t_sphere){.c = *center, .r = op_magnitude(radius)});
}
