/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:00:55 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/21 15:04:42 by brcoppie         ###   ########.fr       */
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

static void	transf_matrix_sp(t_object *sp)
{
	t_matrix	t;
	t_matrix	s;

	t = trsfrm_translate(sp->obj.sp.c.x, sp->obj.sp.c.y, sp->obj.sp.c.z);
	s = trsfrm_scale(sp->obj.sp.r, sp->obj.sp.r, sp->obj.sp.r);
	sp->tr_matrix = matrices_multiply(&t, &s);
	sp->inv_tr = matrix_inverse(&sp->tr_matrix);
}

static void	transf_matrix_pl(t_object *pl)
{
	t_vector	u;
	t_vector	v;
	t_vector	n;

	n = pl->obj.pl.v;
	if (fabs(n.y) > 0.99)
		u = (t_vector){.x = 1, .y = 0, .z = 0, .w = 0};
	else
		u = (t_vector){.x = 0, .y = 1, .z = 0, .w = 0};
	u = op_cross(&u, &n);
	u = op_normalise(&u);
	v = op_cross(&u, &n);
	v = op_normalise(&v);
	pl->tr_matrix.c1 = u;
	pl->tr_matrix.c2 = v;
	pl->tr_matrix.c3 = n;
	pl->tr_matrix.c4 = pl->obj.pl.p;
	pl->inv_tr = matrix_inverse(&pl->tr_matrix);
}

static void	transf_matrix_cy(t_object *cy)
{
	t_vector	u;
	t_vector	v;
	t_vector	n;

	n = cy->obj.cy.v;
	if (fabs(n.y) > 0.99)
		u = (t_vector){.x = 1, .y = 0, .z = 0, .w = 0};
	else
		u = (t_vector){.x = 0, .y = 1, .z = 0, .w = 0};
	u = op_cross(&u, &n);
	u = op_normalise(&u);
	v = op_cross(&u, &n);
	v = op_normalise(&v);
	u = op_multi_scalar(&u, cy->obj.cy.radius);
	v = op_multi_scalar(&v, cy->obj.cy.radius);
	n = op_multi_scalar(&n, cy->obj.cy.height);
	cy->tr_matrix.c1 = u;
	cy->tr_matrix.c2 = v;
	cy->tr_matrix.c3 = n;
	cy->tr_matrix.c4 = cy->obj.cy.c;
	cy->inv_tr = matrix_inverse(&cy->tr_matrix);
}

void	precompute_transformations(t_object *obj_arr, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->size)
	{
		if (obj_arr[i].type == SPHERE)
			transf_matrix_sp(&obj_arr[i]);
		else if (obj_arr[i].type == PLANE)
			transf_matrix_pl(&obj_arr[i]);
		else if (obj_arr[i].type == CYLINDER)
			transf_matrix_cy(&obj_arr[i]);
		i++;
	}
}
