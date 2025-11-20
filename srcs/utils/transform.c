/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:00:55 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/20 18:32:12 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <stdio.h>

t_ray	transform_ray(t_ray *ray, t_matrix *tr_matrix)
{
	t_ray	new_ray;

	//print_matrix("transformation matrix : ", tr_matrix, 4);
	new_ray.origin = matrix_vector_multi(tr_matrix, &ray->origin);
	new_ray.origin.w = 1;
	new_ray.direction = matrix_vector_multi(tr_matrix, &ray->direction);
	new_ray.direction.w = 0;
	new_ray.direction = op_normalise(&new_ray.direction);
	//printf("new_ray.origin = (%f,%f,%f), new_ray.dir = (%f,%f,%f)\n",
    //   				new_ray.origin.x, new_ray.origin.y, new_ray.origin.z,
    //  				new_ray.direction.x, new_ray.direction.y, new_ray.direction.z);
	return (new_ray);
}

void	precompute_transf_sp(t_sphere *sp)
{
	t_matrix	t;
	t_matrix	s;

	t = trsfrm_translate(sp->c.x, sp->c.y, sp->c.z);
	s = trsfrm_scale(sp->r, sp->r, sp->r);
	sp->tr_matrix = matrices_multiply(&t, &s);
	sp->inv_tr = matrix_inverse(&sp->tr_matrix);
}

void	precompute_transformations(t_object *obj_arr, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->size)
	{
		if (obj_arr[i].type == SPHERE)
			precompute_transf_sp(&obj_arr[i].obj.sp);
		i++;
	}
}
