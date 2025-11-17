/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:40:10 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/17 19:14:15 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	sort_intersections(t_intersec_info *intersections, int size)
{
	int				i;
	int				j;
	t_intersec_info	tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (intersections[j].t > intersections[j + 1].t)
			{
				tmp = intersections[j];
				intersections[j] = intersections[j + 1];
				intersections[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	all_ray_intersections(t_scene *scene, t_ray *ray, t_intersec_info *inters)
{
	int				i;
	int				hits;

	i = 0;
	hits = 0;
	while (i < scene->size)
	{
		hits += obj_intersections(&scene->objects[i], ray, inters[hits]);
		i++;
	}
	return (hits);
}
