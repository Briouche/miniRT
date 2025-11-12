/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:55:12 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/11 17:56:34 by fkrakow          ###   ########.fr       */
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

typedef struct s_intersec
{
	double	i1;
	double	i2;
}	t_intersec;

typedef struct s_intersec_info
{
	double		t;
	t_object	*sp;
}	t_intersec_info;

t_ray			ray(t_vector *origin, t_vector *direction);
t_vector		position(t_ray *r, double t);
int				intersect(t_intersec *s, t_sphere *sp, t_ray *r);
t_intersec_info	intersection(t_intersec *intersec);

#endif
