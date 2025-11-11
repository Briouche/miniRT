/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:55:12 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/11 14:27:05 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_intersect
{
	double	i1;
	double	i2;
}	t_intersect;

t_ray		ray(t_vector *origin, t_vector *direction);
t_vector	position(t_ray *r, double t);
int			intersect(t_intersect *s, t_sphere *sp, t_ray *r);

#endif
