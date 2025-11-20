/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:37:24 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/20 16:23:54 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_sphere	sphere(t_vector *center, t_vector *radius)
{
	return ((t_sphere){.c = *center, .r = op_magnitude(radius)});
}

t_plane		plane(t_vector *p, t_vector *v, t_vector *color)
{
	return ((t_plane){.p = *p, .v = *v, .color = *color});
}

t_cylinder	cylinder(t_vector *c, t_vector *v, t_vector *color)
{
	return ((t_cylinder){.c = *c, .v = *v, .color = *color});
}

//t_sphere	unit_sphere()
//{
//	return ((t_sphere){.c = (t_vector){0, 0, 0}, .r = 1});
//}

//t_plane		unit_plane()
//{
//    return ((t_plane){.p = (t_vector){0, 0, 0}, .v = (t_vector){0, 0, 1}});
//}

//t_cylinder	unit_cylinder()
//{
//	return ((t_cylinder){.c = (t_vector){0, 0, 0}, .radius = 1, .v = (t_vector){0, 0, 1}});
//}
