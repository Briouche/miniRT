/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shearing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:02:03 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 17:11:29 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_shearing(void)
{
	t_matrix	trans;
	t_vector	vec;
	t_vector	new_vec;

	printf("\n===== Testing shearing =====\n");
	trans = trsfrm_shear(&(t_vector){0, 1, 0, 0},
			&(t_vector){0, 0, 0, 0});
	vec = (t_vector){2, 3, 4, 1};
	new_vec = matrix_vector_multi(&trans, &vec);
	print_vec("expect: (6, 3, 4) - ", &new_vec);
	trans = trsfrm_shear(&(t_vector){0, 0, 1, 0},
			&(t_vector){0, 0, 0, 0});
	new_vec = matrix_vector_multi(&trans, &vec);
	print_vec("expect: (2, 5, 4) - ", &new_vec);
	trans = trsfrm_shear(&(t_vector){0, 0, 0, 1},
			&(t_vector){0, 0, 0, 0});
	new_vec = matrix_vector_multi(&trans, &vec);
	print_vec("expect: (2, 7, 4) - ", &new_vec);
	trans = trsfrm_shear(&(t_vector){0, 0, 0, 0},
			&(t_vector){1, 0, 0, 0});
	new_vec = matrix_vector_multi(&trans, &vec);
	print_vec("expect: (2, 3, 6) - ", &new_vec);
	return (0);
}
