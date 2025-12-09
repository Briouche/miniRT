/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:55:12 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/09 18:26:48 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

# define PI 3.141592653589793

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_inter_values
{
	double	t1;
	double	t2;
}	t_inter_values;

typedef struct s_inter
{
	double		t;
	t_vector	pos;
	t_object	*obj;
	int			in_shadow;
}	t_inter;

t_ray		ray(t_vector *origin, t_vector *direction);
t_vector	position(t_ray *r, double t);

t_ray		transform_ray(t_ray *ray, t_matrix *tr_matrix);

int			intersect_sp(t_object *sp, t_ray *r, t_inter_values *obj_inter);
int			intersect_pl(t_object *pl, t_ray *r, t_inter_values *obj_inter);
int			intersect_cy(t_object *cy, t_ray *r, t_inter_values *obj_inter);

#endif
