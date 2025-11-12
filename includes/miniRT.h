/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/12 14:45:09 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "utils.h"
# include "display.h"

# include <stdio.h>
# include <fcntl.h>
# include <float.h>

# define WIDTH 900
# define HEIGHT 550

// main functions
int		init_display(t_display *display);
int		render_image(t_display *img);
void	display_loop(t_display *display);

// Ray Tracer chapters
int		cannon_ball(t_display *img, t_vector *color);
int		draw_clock(t_display *img, t_vector *white);

// parsing
int		parsing(const char *filename, t_scene *scene);
int		parse_scene(t_scene *scene, const char *filename);
int		input_error(const char *msg, t_object *obj);

// parse lighting
int		parse_ambient(t_scene *scene, char *const token[]);
int		parse_camera(t_scene *scene, char *const token[]);
int		parse_light(t_scene *scene, char *const token[]);

// parse shapes
int		parse_sphere(t_obj_list **obj_list, int *size, char *const token[]);
int		parse_plane(t_obj_list **obj_list, int *size, char *const token[]);
int		parse_cylinder(t_obj_list **obj_list, int *size, char *const token[]);

// parse utils
int		parse_color(const char *str, t_vector *colors);
int		parse_point(const char *str, t_vector *p);
int		parse_vector(const char *str, t_vector *v);

//DEBUGGING
void	print_scene(t_scene *scene);

// strings
double	ft_atod(const char *str);



#endif
