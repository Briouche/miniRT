/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:09:40 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/06 13:53:45 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include <stdio.h>

void	print_vec(char *const str, t_vector *v)
{
	printf("%s (%.4f, %.4f, %.4f, %.4f)\n", str, v->x, v->y, v->z, v->w);
}

void	print_matrix(const char *str, t_matrix *m, int d)
{
	printf("%s (%dx%d):\n", str, d, d);
	print_vec("", &(t_vector){m->c1.x, m->c2.x, m->c3.x, m->c4.x});
	print_vec("", &(t_vector){m->c1.y, m->c2.y, m->c3.y, m->c4.y});
	print_vec("", &(t_vector){m->c1.z, m->c2.z, m->c3.z, m->c4.z});
	print_vec("", &(t_vector){m->c1.w, m->c2.w, m->c3.w, m->c4.w});
	printf("\n");
}
