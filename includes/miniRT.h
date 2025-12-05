/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/03 13:49:25 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "utils.h"
# include "parser.h"
# include "display.h"

// main functions
int			init_scene(t_scene *scene);
t_ray		generate_cam_ray(int x, int y, t_camera *cam);
t_inter		find_hit(t_scene *scene, t_ray *ray);
t_vector	compute_color(t_scene *scene, t_inter *hit, t_ray *r);


// shading
t_vector	normal_at(t_object *obj, t_vector *p, t_ray *ray);
t_vector	lighting(t_scene *scene, t_material *mat, \
					t_vector *pos, t_vector *normalv);




#endif
