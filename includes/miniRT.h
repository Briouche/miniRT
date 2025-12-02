/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 17:57:47 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "utils.h"
# include "parser.h"
# include "display.h"

// main functions
t_ray	generate_camera_ray(int x, int y, t_camera *cam);

// Ray Tracer chapters
int		cannon_ball(t_display *img, t_vector *color);
int		draw_clock(t_display *img, t_vector *white);

// shading
t_vector	normal_at(t_object *obj, t_vector *p, t_ray *ray);
t_vector	lighting(t_scene *scene, t_material *mat, \
					t_vector *pos, t_vector *normalv);
t_vector	compute_final_color(t_scene *scene, t_inter *hit, t_ray *r);

//DEBUGGING
void	print_scene(t_scene *scene);
void	sphere_silhouette(t_scene *scene, t_display *img);

#endif
