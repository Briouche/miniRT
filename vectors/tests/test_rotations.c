/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:29:22 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 16:58:35 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	test_around_x(t_matrix *trans, t_vector *vec)
{
	t_vector	new_vec;
	double		pi_2;

	pi_2 = M_PI_2;
	*trans = trsfrm_rotate_x(&pi_2);
	*vec = (t_vector){0, 1, 0, 1};
	new_vec = matrix_vector_multi(trans, vec);
	print_vec("expect: (0, 0, 1) - ", &new_vec);
	return (0);
}

static int	test_around_y(t_matrix *trans, t_vector *vec)
{
	t_vector	new_vec;
	double		pi_2;

	pi_2 = M_PI_2;
	*trans = trsfrm_rotate_y(&pi_2);
	*vec = (t_vector){0, 0, 1, 1};
	new_vec = matrix_vector_multi(trans, vec);
	print_vec("expect: (1, 0, 0) - ", &new_vec);
	return (0);
}

static int	test_around_z(t_matrix *trans, t_vector *vec)
{
	t_vector	new_vec;
	double		pi_2;

	pi_2 = M_PI_2;
	*trans = trsfrm_rotate_z(&pi_2);
	*vec = (t_vector){0, 1, 0, 1};
	new_vec = matrix_vector_multi(trans, vec);
	print_vec("expect: (-1, 0, 0) - ", &new_vec);
	return (0);
}

int	test_rotations(void)
{
	t_matrix	trans;
	t_vector	vec;

	printf("\n===== Testing the three rotations =====\n");
	test_around_x(&trans, &vec);
	test_around_y(&trans, &vec);
	test_around_z(&trans, &vec);
	return (0);
}
