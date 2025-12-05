/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:40:10 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 16:58:36 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static int	intersect_obj(t_object *obj, t_ray *ray, t_inter *inters)
{
	t_inter_values	obj_inter;

	if (obj->type == SPHERE)
	{
		if (!intersect_sp(obj, ray, &obj_inter))
			return (0);
	}
	else if (obj->type == PLANE)
	{
		if (!intersect_pl(obj, ray, &obj_inter))
			return (0);
	}
	else if (obj->type == CYLINDER)
	{
		if (!intersect_cy(obj, ray, &obj_inter))
			return (0);
	}
	inters[0].obj = obj;
	inters[0].t = obj_inter.t1;
	inters[1].obj = obj;
	inters[1].t = obj_inter.t2;
	return (2);
}

static int	ray_intersect_objs(t_scene *scene, t_ray *ray, t_inter *inters)
{
	int		i;
	int		hits;

	i = 0;
	hits = 0;
	while (i < scene->size)
		hits += intersect_obj(&scene->objects[i++], ray, &inters[hits]);
	return (hits);
}

t_inter	find_hit(t_scene *scene, t_ray *ray)
{
	t_inter	hit;
	t_inter	*inters;
	int		n;
	int		nbr_hits;

	inters = scene->inters;
	nbr_hits = ray_intersect_objs(scene, ray, inters);
	if (!nbr_hits)
		return ((t_inter){.t = -1});
	hit = (t_inter){.t = INFINITY};
	n = -1;
	while (++n < nbr_hits)
		if (inters[n].t < hit.t && inters[n].t > 0.00001)
			hit = inters[n];
	return (hit);
}
