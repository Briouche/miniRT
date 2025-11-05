/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:04:26 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 17:03:38 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <unistd.h>
# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector;

typedef struct s_matrix
{
	t_vector	c1;
	t_vector	c2;
	t_vector	c3;
	t_vector	c4;
}	t_matrix;

// Colors
t_vector	add_colors(t_vector *a, t_vector *b);
t_vector	multi_colors(t_vector *a, t_vector *b);
t_vector	multi_scalar_colors(t_vector *a, double *n);
t_vector	sub_colors(t_vector *a, t_vector *b);

t_vector	vec_color(double *red, double *green, double *blue);

// Vectors
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

// matrices
t_matrix	matrix(t_vector *a, t_vector *b, t_vector *c, t_vector *d);

int			is_equal_matrix(t_matrix *a, t_matrix *b);

t_matrix	matrices_add(t_matrix *a, t_matrix *b);
t_matrix	matrices_multiply(t_matrix *a, t_matrix *b);

double		matrix_cofactor(t_matrix *m, int r, int c, int d);
double		matrix_det_d2(t_vector *m);
double		matrix_determinant(t_matrix *m, int d);
double		matrix_minor(t_matrix *m, int r, int c, int d);

t_matrix	matrix_inverse(t_matrix *m);
t_matrix	matrix_reduce(t_matrix *m, int r, int c);
t_matrix	matrix_transpose(t_matrix *m);
t_vector	matrix_vector_multi(t_matrix *m, t_vector *v);

// transformations
t_matrix	trsfrm_rotate_x(double *angle);
t_matrix	trsfrm_rotate_y(double *angle);
t_matrix	trsfrm_rotate_z(double *angle);
t_matrix	trsfrm_scale(double *x, double *y, double *z);
t_matrix	trsfrm_shear(t_vector *a, t_vector *b);
t_matrix	trsfrm_translate(double *x, double *y, double *z);

#endif
