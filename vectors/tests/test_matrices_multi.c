/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrices_multi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:12:01 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 10:01:54 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	set_matrices(t_matrix *a, t_matrix *b, int n)
{
	if (n == 0)
	{
		*a = (t_matrix){{1, 0, 0, 0}, {0, 1, 0, 0},
		{0, 0, 1, 0}, {0, 0, 0, 1}};
		*b = (t_matrix){{1, 2, 3, 4}, {5, 6, 7, 8},
		{9, 10, 11, 12}, {13, 14, 15, 16}};
	}
	else if (n == 1)
	{
		*a = (t_matrix){{1, 2, 3, 4}, {4, 5, 6, 8},
		{9, 10, 11, 12}, {13, 14, 15, 16}};
		*b = (t_matrix){{17, 18, 19, 20}, {21, 22, 23, 24},
		{25, 26, 27, 28}, {29, 30, 31, 32}};
	}
	else if (n == 2)
	{
		*a = (t_matrix){{2, 0, 0, 0}, {0, 2, 0, 0},
		{0, 0, 2, 0}, {0, 0, 0, 1}};
		*b = (t_matrix){{1, 0, 0, 5}, {0, 1, 0, 3},
		{0, 0, 1, 2}, {0, 0, 0, 1}};
	}
}

static void	test_multi(t_matrix *a, t_matrix *b)
{
	t_matrix	result;

	print_matrix("Matrix A: ", a, 4);
	print_matrix("Matrix B: ", b, 4);
	result = matrices_multiply(a, b);
	print_matrix("Result: A x B = ", &result, 4);
}

int	test_matrices_multi(void)
{
	t_matrix	a;
	t_matrix	b;

	set_matrices(&a, &b, 0);
	printf("=== Test 1: Multiplication with Identity Matrix ===\n");
	test_multi(&a, &b);
	set_matrices(&a, &b, 1);
	printf("=== Test 2: General Multiplication ================\n");
	test_multi(&a, &b);
	set_matrices(&a, &b, 2);
	printf("=== Test 3: Scale and Translate ===================\n");
	test_multi(&a, &b);
	return (0);
}
