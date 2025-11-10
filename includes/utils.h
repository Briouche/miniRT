/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:55:12 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:38:14 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

t_ray		ray(t_vector *origin, t_vector *direction);
t_vector	position(t_ray *r, double t);

#endif
