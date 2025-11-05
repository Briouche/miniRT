/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_reductions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:37:55 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 10:01:14 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	set_matrix(t_matrix *m)
{
	*m = (t_matrix){{1, 2, 3, 4}, {5, 6, 7, 8},
	{9, 10, 11, 12}, {13, 14, 15, 16}};
}

int	test_matrix_reductions(void)
{
	t_matrix	m;
	t_matrix	res;

	set_matrix(&m);
	print_matrix("matrix m: ", &m, 4);
	printf("testing matrix reduction (2, 1)\n");
	res = matrix_reduce(&m, 2, 1);
	print_matrix("reduce matrix", &res, 4);
	printf("testing matrix reduction (3, 3)\n");
	res = matrix_reduce(&m, 3, 3);
	print_matrix("reduce matrix", &res, 4);
	printf("testing matrix reduction (2, 1)\n");
	res = matrix_reduce(&m, 2, 1);
	print_matrix("reduce matrix", &res, 4);
	printf("testing matrix reduction (2, 0)\n");
	res = matrix_reduce(&m, 2, 0);
	print_matrix("reduce matrix", &res, 4);
	return (0);
}
