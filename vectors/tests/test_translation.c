/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_translation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:28:49 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 13:30:32 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	test_point_translation(t_vector *pos, t_matrix *trans)
{
	t_vector	new_pos;

	print_vec("point p: ", pos);
	new_pos = matrix_vector_multi(trans, pos);
	print_vec("point p after translation: ", &new_pos);
	return (0);
}

static int	test_point_translate_back(t_vector *pos, t_matrix *trans)
{
	t_matrix	inv;
	t_vector	new_pos;

	print_vec("point p: ", pos);
	inv = matrix_inverse(trans);
	new_pos = matrix_vector_multi(&inv, pos);
	print_vec("point p after translation: ", &new_pos);
	return (0);
}

static int	test_vector_translation(t_vector *vec, t_matrix *trans)
{
	t_vector	new_vec;

	print_vec("vector v: ", vec);
	new_vec = matrix_vector_multi(trans, vec);
	print_vec("vector v after translation: ", &new_vec);
	return (0);
}

int	test_translation(void)
{
	t_vector	vec;
	t_matrix	trans;
	double		coordinates[3];

	coordinates[0] = -3;
	coordinates[1] = 4;
	coordinates[2] = 5;
	vec = point(&coordinates[0], &coordinates[1], &coordinates[2]);
	coordinates[0] = 5;
	coordinates[1] = -3;
	coordinates[2] = 2;
	trans = trsfrm_translate(&coordinates[0], &coordinates[1], &coordinates[2]);
	test_point_translation(&vec, &trans);
	test_point_translate_back(&vec, &trans);
	vec.w = 0;
	test_vector_translation(&vec, &trans);
	return (0);
}
