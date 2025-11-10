/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:27:10 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 15:04:13 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_vec(char *const str, t_vector *v);
void	print_matrix(const char *str, t_matrix *m, int d);

//int	main()
//{
//	t_matrix	m1;
// 	t_matrix	m2;
//	t_matrix	m3;
//	t_matrix	m4;
//	t_vector	v1 = (t_vector){1, 1, 1, 5};

// 	m1 = (t_matrix){
// 		(t_vector){-2, -3, 1, -6},
// 		(t_vector){-8, 1, 2, 7},
// 		(t_vector){3, 7, -9, 7},
// 		(t_vector){5, 3, 6, -9}
// 	};
// 	m2 = (t_matrix){
// 		(t_vector){8, 7, -6, -3},
// 		(t_vector){-0, 0, 5, 0},
// 		(t_vector){9, 6, 9, -9},
// 		(t_vector){2, 1, 6, -4}
// 	};
//	m3 = (t_matrix){
// 		(t_vector){1, 0, 5, 0},
// 		(t_vector){0, 1, 0, 0},
// 		(t_vector){0, 0, 1, 0},
// 		(t_vector){0, 0, 0, 1}
// 	};
//	if (is_equal_matrix(&m1, &m2))
//		printf("m1 == m2\n");
//	else
//	printf("m1 != m2\n");
//	printf("m1[23] : %f\n", m1.c2.z);
//	m4 = matrices_multiply(&m1, &m2);
//	print_matrix("m1 * m2 = ", &m4, 4);
//	m4 = matrix_transpose(&m4);
//	print_matrix("m4[T] = ", &m4, 4);
//	print_matrix("m1 :", &m1, 4);
//	printf("determinant of m1 : %f\n", matrix_determinant(&m1, 4));
//	print_matrix("m4 :", &m4, 4);
//	m4 = matrix_inverse(&m4);
//	print_matrix("inverse of m4 :", &m4, 4);
//	v1 = matrix_vector_multi(&m3, &v1);
//	print_vec("v1 :", &v1);
//}

//int	main(int argc, char *const argv[])
//{
//	(void)argc;
//	(void)argv;
//	test_matrices_multi();
//	test_matrix_reductions();
//	test_translation();
//	test_rotations();
//	test_shearing();
//	return (0);
//}

// void	test_matrices(void)
// {
// 	t_matrix	m1;
// 	t_matrix	m2;
// 	t_matrix	m3;
// 	double		det;

// 	printf("=== Testing 3x3 Matrices ===\n\n");

// 	m1 = (t_matrix){
// 		(t_vector){1, -5, 2, 0},
// 		(t_vector){2, 8, 6, 0},
// 		(t_vector){6, -4, 4, 0},
// 		(t_vector){0, 0, 0, 0}
// 	};
// 	print_matrix(&m1, 3);
// 	det = matrix_determinant(&m1, 3);
// 	printf("Determinant: %.2f (Expected: -196.00)\n\n", det);

// 	m2 = (t_matrix){
// 		(t_vector){-2, -3, 1, -6},
// 		(t_vector){-8, 1, 2, 7},
// 		(t_vector){3, 7, -9, 7},
// 		(t_vector){5, 3, 6, -9}
// 	};
// 	print_matrix(&m2, 3);
// 	det = matrix_determinant(&m2, 4);
// 	printf("Determinant: %.2f (Expected: -4071.00)\n\n", det);

// 	// Test 3: Another 3x3 matrix

// 	m3 = (t_matrix){
// 		(t_vector){0, 0, 0, 0},
// 		(t_vector){0, 0, 0, 0},
// 		(t_vector){0, 0, 0, 0},
// 		(t_vector){0, 0, 0, 0}
// 	};
// 	print_matrix(&m3, 3);
// 	det = matrix_determinant(&m3, 3);
// 	printf("Determinant: %.2f (Expected: 0)\n\n", det);
// }

// int	main(void)
// {
// 	test_matrices();
// 	return (0);
// }

// void	test_inverse_matrix(void)
// {
// 	t_matrix	m1;
// 	t_matrix	m2;
// 	t_matrix	m3;
// 	t_matrix	inverse;

// 	printf("=== Testing 3x3 Matrices ===\n\n");

// 	m1 = (t_matrix){
// 		(t_vector){8, 7, -6, -3},
// 		(t_vector){-5, 5, 0, 0},
// 		(t_vector){9, 6, 9, -9},
// 		(t_vector){2, 1, 6, -4}
// 	};
// 	inverse = matrix_inverse(&m1, 4);
// 	print_matrix(&inverse, 4);
// }

// static void	test_inverse_product(void)
// {
// 	t_matrix	a;
// 	t_matrix	b;
// 	t_matrix	c;

// 	a = (t_matrix){
// 		(t_vector){3, 3, -4, -6},
// 		(t_vector){-9, -8, 4, 5},
// 		(t_vector){7, 2, 4, -1},
// 		(t_vector){3, -9, 1, 1}
// 	};
// 	b = (t_matrix){
// 		(t_vector){8, 3, 7, 6},
// 		(t_vector){2, -1, 0, -2},
// 		(t_vector){2, 7, 5, 0},
// 		(t_vector){2, 0, 4, 5}
// 	};

// 	c = matrices_multiply(&a, &b);
// 	b = matrix_inverse(&b, 0);
// 	c = matrices_multiply(&c, &b);
// 	print_matrix(&a, 4);
// 	print_matrix(&c, 4);
// 	printf("true: 1, false 0; is true? %d\n", is_equal_matrix(&a, &c));
// }

// int	main(void)
// {
// 	test_inverse_matrix();
// 	test_inverse_product();
// 	return (0);
// }
