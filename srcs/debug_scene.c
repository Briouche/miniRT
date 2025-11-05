/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:20:42 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/05 17:16:33 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void print_color(t_colors color)
{
    printf("R:%d G:%d B:%d", color.R, color.G, color.B);
}

void print_point(t_point p)
{
    printf("(%.2f, %.2f, %.2f)", p.x, p.y, p.z);
}

void print_vector(t_vec v)
{
    printf("(%.2f, %.2f, %.2f)", v.x, v.y, v.z);
}

void print_object(t_object *obj)
{
    if (!obj)
        return;
    printf("Type: ");
    switch (obj->type)
    {
        case SPHERE:
            printf("Sphere\n");
            printf("  Center: "); print_point(obj->obj.sp.center); printf("\n");
            printf("  Diameter: %.2f\n", obj->obj.sp.diameter);
            printf("  Color: "); print_color(obj->obj.sp.color); printf("\n");
            break;
        case PLANE:
            printf("Plane\n");
            printf("  Point: "); print_point(obj->obj.pl.p); printf("\n");
            printf("  Normal: "); print_vector(obj->obj.pl.v); printf("\n");
            printf("  Color: "); print_color(obj->obj.pl.color); printf("\n");
            break;
        case CYLINDER:
            printf("Cylinder\n");
            printf("  Center: "); print_point(obj->obj.cy.center); printf("\n");
            printf("  Vector: "); print_vector(obj->obj.cy.v); printf("\n");
            printf("  Diameter: %.2f\n", obj->obj.cy.diameter);
            printf("  Height: %.2f\n", obj->obj.cy.height);
            printf("  Color: "); print_color(obj->obj.cy.color); printf("\n");
            break;
    }
}

void print_scene(t_scene *scene)
{
    if (!scene)
        return;

    printf("=== Scene ===\n");

    printf("Ambient Light:\n");
    printf("  Ratio: %.2f\n", scene->ambient_light.ratio);
    printf("  Color: "); print_color(scene->ambient_light.color); printf("\n");

    printf("Camera:\n");
    printf("  Viewpoint: "); print_point(scene->cam.viewpoint); printf("\n");
    printf("  Orientation: "); print_vector(scene->cam.orientation); printf("\n");
    printf("  FOV: %.2f\n", scene->cam.fov);

    printf("Light:\n");
    printf("  Coord: "); print_point(scene->light.coord); printf("\n");
    printf("  Ratio: %.2f\n", scene->light.ratio);
    printf("  Color: "); print_color(scene->light.color); printf("\n");

    printf("Objects (%d):\n", scene->count.obj_count);
    for (int i = 0; i < scene->count.obj_count; i++)
    {
        printf("Object %d:\n", i + 1);
        print_object(&scene->objects[i]);
        printf("\n");
    }
}
