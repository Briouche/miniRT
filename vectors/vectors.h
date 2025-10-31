/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:04:26 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 15:39:51 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector;

t_vector	add_colors(t_vector *a, t_vector *b);
t_vector	multi_colors(t_vector *a, t_vector *b);
t_vector	multi_scalar_colors(t_vector *a, double *n);
t_vector	sub_colors(t_vector *a, t_vector *b);

t_vector	vec_color(double *red, double *green, double *blue);

int			is_equal(t_vector *a, t_vector *b);
int			is_point(t_vector *v);
int			is_vector(t_vector *v);

t_vector	op_cross(t_vector *a, t_vector *b);
double		op_dot(t_vector *a, t_vector *b);
double		op_magnitude(t_vector *v);
t_vector	op_minus(t_vector *a, t_vector *b);
t_vector	op_multi(t_vector *v, double *scalar);
t_vector	op_normalise(t_vector *v);
t_vector	op_opposite(t_vector *v);
t_vector	op_plus(t_vector *a, t_vector *b);

t_vector	point(double *x, double *y, double *z);
t_vector	vector(double *x, double *y, double *z);

#endif
