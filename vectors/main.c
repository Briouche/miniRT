// #include <stdio.h>
// #include "vectors.h"

// // Helper function to print a matrix
// void print_matrix(const char *name, t_matrix *m)
// {
// 	printf("%s:\n", name);
// 	printf("  [%8.3f %8.3f %8.3f %8.3f]\n", m->c1.x, m->c2.x, m->c3.x, m->c4.x);
// 	printf("  [%8.3f %8.3f %8.3f %8.3f]\n", m->c1.y, m->c2.y, m->c3.y, m->c4.y);
// 	printf("  [%8.3f %8.3f %8.3f %8.3f]\n", m->c1.z, m->c2.z, m->c3.z, m->c4.z);
// 	printf("  [%8.3f %8.3f %8.3f %8.3f]\n\n", m->c1.w, m->c2.w, m->c3.w, m->c4.w);
// }

// int main(void)
// {
// 	t_matrix a, b, result;

// 	printf("=== Test 1: Identity Matrix × Any Matrix ===\n");
// 	// Identity matrix
// 	a = (t_matrix){
// 		{1, 0, 0, 0},  // c1
// 		{0, 1, 0, 0},  // c2
// 		{0, 0, 1, 0},  // c3
// 		{0, 0, 0, 1}   // c4
// 	};
	
// 	// Simple matrix
// 	b = (t_matrix){
// 		{1, 2, 3, 4},
// 		{5, 6, 7, 8},
// 		{9, 10, 11, 12},
// 		{13, 14, 15, 16}
// 	};

// 	print_matrix("Identity Matrix", &a);
// 	print_matrix("Matrix B", &b);
// 	result = matrices_multiply(&a, &b);
// 	print_matrix("Result (should equal B)", &result);

// 	printf("=== Test 2: Simple Multiplication ===\n");
// 	a = (t_matrix){
// 		{1, 2, 3, 4},
// 		{0, 1, 0, 0},
// 		{0, 0, 1, 0},
// 		{0, 0, 0, 1}
// 	};

// 	b = (t_matrix){
// 		{1, 0, 0, 0},
// 		{0, 1, 0, 0},
// 		{0, 0, 1, 0},
// 		{0, 0, 0, 1}
// 	};

// 	print_matrix("Matrix A", &a);
// 	print_matrix("Matrix B", &b);
// 	result = matrices_multiply(&a, &b);
// 	print_matrix("Result", &result);

// 	printf("=== Test 3: Scale and Translate ===\n");
// 	// Scale matrix (2x in all directions)
// 	a = (t_matrix){
// 		{2, 0, 0, 0},
// 		{0, 2, 0, 0},
// 		{0, 0, 2, 0},
// 		{0, 0, 0, 1}
// 	};

// 	// Translation matrix
// 	b = (t_matrix){
// 		{1, 0, 0, 5},
// 		{0, 1, 0, 3},
// 		{0, 0, 1, 2},
// 		{0, 0, 0, 1}
// 	};

// 	print_matrix("Scale Matrix (2x)", &a);
// 	print_matrix("Translation Matrix", &b);
// 	result = matrices_multiply(&a, &b);
// 	print_matrix("Result", &result);

// 	printf("=== Test 4: General Multiplication ===\n");
// 	a = (t_matrix){
// 		{1, 2, 3, 4},
// 		{5, 6, 7, 8},
// 		{9, 10, 11, 12},
// 		{13, 14, 15, 16}
// 	};
// 	// (1, 5,  9, 13)
// 	// (2, 6, 10, 14)
// 	// (3, 7, 11, 15)
// 	// (4, 8, 12, 16)

// 	b = (t_matrix){
// 		{1, 0, 0, 1},
// 		{0, 1, 0, 1},
// 		{0, 0, 1, 1},
// 		{1, 1, 1, 1}
// 	};

// 	print_matrix("Matrix A", &a);
// 	print_matrix("Matrix B", &b);
// 	result = matrices_multiply(&a, &b);
// 	print_matrix("Result", &result);

// 	printf("testint matrix reduction (2, 1)\n");
// 	result = matrix_reduce(&a, 2, 1);
// 	print_matrix("Matrix A", &result);

// 	printf("testint matrix reduction (3, 3)\n");
// 	result = matrix_reduce(&a, 3, 3);
// 	print_matrix("Matrix A", &result);
	
// 	printf("testint matrix reduction (2, 4)\n");
// 	result = matrix_reduce(&a, 2, 4);
// 	print_matrix("Matrix A", &result);

// 	printf("testint matrix reduction (4, 0)\n");
// 	result = matrix_reduce(&a, 4, 0);
// 	print_matrix("Matrix A", &result);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_determinant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:15:00 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/04 12:15:00 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vectors.h"
// #include <stdio.h>

// void	print_matrix(t_matrix *m, int d)
// {
// 	printf("Matrix %dx%d:\n", d, d);
// 	printf("%.2f %.2f %.2f %.2f\n", m->c1.x, m->c2.x, m->c3.x, m->c4.x);
// 	printf("%.2f %.2f %.2f %.2f\n", m->c1.y, m->c2.y, m->c3.y, m->c4.y);
// 	printf("%.2f %.2f %.2f %.2f\n", m->c1.z, m->c2.z, m->c3.z, m->c4.z);
// 	printf("%.2f %.2f %.2f %.2f\n", m->c1.w, m->c2.w, m->c3.w, m->c4.w);
// 	printf("\n");
// }

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



#include "vectors.h"
#include <stdio.h>

void	print_matrix(t_matrix *m, int d)
{
	printf("Matrix %dx%d:\n", d, d);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.x, m->c2.x, m->c3.x, m->c4.x);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.y, m->c2.y, m->c3.y, m->c4.y);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.z, m->c2.z, m->c3.z, m->c4.z);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.w, m->c2.w, m->c3.w, m->c4.w);
	printf("\n");
}

void	test_inverse_matrix(void)
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m3;
	t_matrix		inverse;

	printf("=== Testing 3x3 Matrices ===\n\n");

	m1 = (t_matrix){
		(t_vector){8, 7, -6, -3},
		(t_vector){-5, 5, 0, 0},
		(t_vector){9, 6, 9, -9},
		(t_vector){2, 1, 6, -4}
	};
	inverse = matrix_inverse(&m1, 4);
	print_matrix(&inverse, 4);
}

static void	test_inverse_product(void)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;

	a = (t_matrix){
		(t_vector){3, 3, -4, -6},
		(t_vector){-9, -8, 4, 5},
		(t_vector){7, 2, 4, -1},
		(t_vector){3, -9, 1, 1}
	};
	b = (t_matrix){
		(t_vector){8, 3, 7, 6},
		(t_vector){2, -1, 0, -2},
		(t_vector){2, 7, 5, 0},
		(t_vector){2, 0, 4, 5}
	};

	c = matrices_multiply(&a, &b);
	b = matrix_inverse(&b, 0);
	c = matrices_multiply(&c, &b);
	print_matrix(&a, 4);
	print_matrix(&c, 4);
	printf("true: 1, false 0; is true? %d\n", is_equal_matrix(&a, &c));
}

int	main(void)
{
	test_inverse_matrix();
	test_inverse_product();
	return (0);
}
