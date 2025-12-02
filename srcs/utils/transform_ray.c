/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:52:15 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 16:52:23 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_ray	transform_ray(t_ray *ray, t_matrix *tr_matrix)
{
	t_ray	new_ray;

	new_ray.origin = matrix_vector_multi(tr_matrix, &ray->origin);
	new_ray.origin.w = 1;
	new_ray.direction = matrix_vector_multi(tr_matrix, &ray->direction);
	new_ray.direction.w = 0;
	new_ray.direction = op_normalise(&new_ray.direction);
	return (new_ray);
}
