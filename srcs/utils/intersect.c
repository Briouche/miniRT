/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:40:10 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/20 18:38:59 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

//DO NOT USE THIS --> bubble sort, way too many operations
//					--> insertion sort maybe, or just keep smallest positive
//void	sort_intersections(t_intersec_info *intersections, int size)
//{
//	int				i;
//	int				j;
//	t_intersec_info	tmp;

//	i = 0;
//	j = 0;
//	while (i < size - 1)
//	{
//		while (j < size - i - 1)
//		{
//			if (intersections[j].t > intersections[j + 1].t)
//			{
//				tmp = intersections[j];
//				intersections[j] = intersections[j + 1];
//				intersections[j + 1] = tmp;
//			}
//			j++;
//		}
//		j = 0;
//		i++;
//	}
//}

static int	obj_intersections(t_object *obj, t_ray *ray, t_intersec_info *inters)
{
	t_intersec	obj_inter;

	if (obj->type == SPHERE)
	{
		if (!intersect_sp(&obj->obj.sp, ray, &obj_inter))
			return (0);
	}
	else if (obj->type == PLANE)
	{
		if (!intersect_pl(&obj->obj.pl, ray, &obj_inter))
			return (0);
	}
	else if (obj->type == CYLINDER)
	{
		if (!intersect_cy(&obj->obj.cy, ray, &obj_inter))
			return (0);
	}
	inters[0].obj = obj;
	inters[0].t = obj_inter.t1;
	inters[1].obj = obj;
	inters[1].t = obj_inter.t2;
	return (2);
}

int	ray_all_intersections(t_scene *scene, t_ray *ray, t_intersec_info *inters)
{
	int				i;
	int				hits;

	i = 0;
	hits = 0;
	while (i < scene->size)
	{
		hits += obj_intersections(&scene->objects[i], ray, &inters[hits]);
		i++;
	}
	return (hits);
}

int	the_hit(t_intersec_info *inters, t_scene *scene)
{
	int	i;
	int	mem;

	i = 0;
	mem = 2147483647;
	while (i < scene->size)
	{
		if (inters[i].t > 0 && inters[i].t < mem)
			mem = i;
		i++;
	}
	return (mem);
}
