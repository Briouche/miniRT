/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:20:42 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/17 16:53:29 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	print_object(t_object *obj)
{
	if (obj && obj->type == SPHERE)
	{
		printf("Sphere\n");
		print_vec("\tCenter: ", &obj->obj.sp.c);
		printf("\tRadius: %.2f\n", obj->obj.sp.r);
		print_vec("\tColor: ", &obj->obj.sp.color);
	}
	else if (obj && obj->type == PLANE)
	{
		printf("Plane\n");
		print_vec("\tPoint: ", &obj->obj.pl.p);
		print_vec("\tNormal: ", &obj->obj.pl.v);
		print_vec("\tColor: ", &obj->obj.pl.color);
	}
	else if (obj && obj->type == CYLINDER)
	{
		printf("Cylinder\n");
		print_vec("\tCenter: ", &obj->obj.cy.c);
		print_vec("\tVector: ", &obj->obj.cy.v);
		printf("\tRadius: %.2f\n", obj->obj.cy.radius);
		printf("\tHeight: %.2f\n", obj->obj.cy.height);
		print_vec("\tColor: ", &obj->obj.cy.color);
	}
	else
		printf("Unkown type\n");
}

void	print_scene(t_scene *scene)
{
	int	n;

	printf("============ Scene =========\n");
	printf("Ambient Light:\n");
	printf("\tRatio: %.2f\n", scene->ambient.ratio);
	print_vec("\tColor: ", &scene->ambient.color);
	printf("Camera:\n");
	print_vec("\tViewpoint: ", &scene->cam.viewpoint);
	print_vec("\tOrientation: ", &scene->cam.orientation);
	printf("\tFOV: %.2f\n", scene->cam.fov);
	printf("Light:\n");
	print_vec("\tCoord: ", &scene->light.coord);
	printf("\tRatio: %.2f\n", scene->light.ratio);
	print_vec("\tColor: ", &scene->light.color);
	printf("Total of number of objects: %d\n", scene->size);
	n = -1;
	while (++n < scene->size)
	{
		printf("Object %d:\n", n);
		print_object(&scene->objects[n]);
		printf("\n");
	}
}
