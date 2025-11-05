/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:09:40 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 09:42:22 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_matrix(const char *str, t_matrix *m, int d)
{
	printf("%s (%dx%d):\n", str, d, d);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.x, m->c2.x, m->c3.x, m->c4.x);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.y, m->c2.y, m->c3.y, m->c4.y);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.z, m->c2.z, m->c3.z, m->c4.z);
	printf("%.2f %.2f %.2f %.2f\n", m->c1.w, m->c2.w, m->c3.w, m->c4.w);
	printf("\n");
}
