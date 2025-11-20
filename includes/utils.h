/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:55:12 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/20 18:35:59 by brcoppie         ###   ########.fr       */
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

typedef struct s_intersec
{
	double	t1;
	double	t2;
}	t_intersec;

typedef struct s_intersec_info
{
	double					t;
	t_object				*obj;
}	t_intersec_info;

t_ray			ray(t_vector *origin, t_vector *direction);
t_vector		position(t_ray *r, double t);

t_ray			transform_ray(t_ray *ray, t_matrix *tr_matrix);
void			precompute_transf_sp(t_sphere	*sp);
void			precompute_transformations(t_object *obj_arr, t_scene *scene);

int				ray_all_intersections(t_scene *scene, t_ray *ray, t_intersec_info *inters);
int				the_hit(t_intersec_info *inters, t_scene *scene);
int				intersect_sp(t_sphere *sp, t_ray *r, t_intersec *obj_inter);
int				intersect_pl(t_plane *pl, t_ray *r, t_intersec *obj_inter);
int				intersect_cy(t_cylinder *cy, t_ray *r, t_intersec *obj_inter);

t_sphere		sphere(t_vector *center, t_vector *radius);

#endif
