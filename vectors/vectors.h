/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:04:26 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/17 17:10:06 by brcoppie         ###   ########.fr       */
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

void		print_vec(char *const str, t_vector *v);
void		print_matrix(const char *str, t_matrix *m, int d);

// Colors
t_vector	add_colors(const t_vector *a, const t_vector *b);
t_vector	multi_colors(const t_vector *a, const t_vector *b);
t_vector	multi_scalar_colors(const t_vector *a, const double n);
t_vector	sub_colors(const t_vector *a, const t_vector *b);

t_vector	vec_color(const double red, const double green, const double blue);

// Vectors
int			is_equal(const t_vector *a, const t_vector *b);
int			is_point(const t_vector *v);
int			is_vector(const t_vector *v);

t_vector	op_cross(const t_vector *a, const t_vector *b);
double		op_dot(const t_vector *a, const t_vector *b);
double		op_magnitude(const t_vector *v);
t_vector	op_minus(const t_vector *a, const t_vector *b);
t_vector	op_multi_scalar(const t_vector *v, const double n);
t_vector	op_normalise(const t_vector *v);
t_vector	op_opposite(const t_vector *v);
t_vector	op_plus(const t_vector *a, const t_vector *b);
t_vector	op_perpendicular_comp(t_vector *v, t_vector *axis);

t_vector	point(const double x, const double y, const double z);
t_vector	vector(const double x, const double y, const double z);

// matrices
t_matrix	matrix(const t_vector *a, const t_vector *b,
				const t_vector *c, const t_vector *d);

int			is_equal_matrix(const t_matrix *a, const t_matrix *b);

t_matrix	matrices_add(const t_matrix *a, const t_matrix *b);
t_matrix	matrices_multiply(const t_matrix *a, const t_matrix *b);

double		matrix_cofactor(const t_matrix *m, const int r,
				const int c, const int d);
double		matrix_det_d2(const t_vector *m);
double		matrix_determinant(const t_matrix *m, const int d);
double		matrix_minor(const t_matrix *m, const int r,
				const int c, const int d);

t_matrix	matrix_inverse(const t_matrix *m);
t_matrix	matrix_reduce(const t_matrix *m, const int r, const int c);
t_matrix	matrix_transpose(const t_matrix *m);
t_vector	matrix_vector_multi(const t_matrix *m, const t_vector *v);

// transformations
t_matrix	trsfrm_rotate_x(const double angle);
t_matrix	trsfrm_rotate_y(const double angle);
t_matrix	trsfrm_rotate_z(const double angle);
t_matrix	trsfrm_scale(const double x, const double y, const double z);
t_matrix	trsfrm_shear(const t_vector *a, const t_vector *b);
t_matrix	trsfrm_translate(const double x, const double y, const double z);

#endif
