/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:07:18 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 12:17:39 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <vectors.h>

t_vector	add_colors(t_vector *a, t_vector *b);
t_vector	color(double *red,  double *green, double *blue);
t_vector	multi_colors(t_vector *a, t_vector *b);
t_vector	multi_scalar_colors(t_vector *a, double *n);
t_vector	sub_colors(t_vector *a, t_vector *b);

#endif