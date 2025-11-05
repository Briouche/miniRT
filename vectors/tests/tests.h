/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 08:55:30 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 09:43:06 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "../vectors.h"
# include <stdio.h>

void	print_matrix(const char *str, t_matrix *m, int d);

int		test_matrices_multi(void);
int		test_matrix_reductions(void);

#endif
