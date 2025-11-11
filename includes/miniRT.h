/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/11 14:43:01 by fkrakow          ###   ########.fr       */
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

//parsing
int		check_filename(char *filename);
int		check_openread(char *filename);
int		list_to_array(t_scene *scene, t_obj_list *objects);
int		parse_scene(t_scene *scene, char *filename);
int		parsing(int ac, char *filename, t_scene *scene);
char	**tokenize_line(int fd);
int		parse_line(t_scene *scene, t_obj_list **objects, char **tokens);
int		parse_point(char *str, t_vector *p);
int		parse_vector(char *str, t_vector *v);
int		parse_color(char *str, t_vector *colors);
int		parse_camera(t_scene *scene, char **line);
int		parse_ambient(t_scene *scene, char **line);
int		parse_light(t_scene *scene, char **line);
int		parse_sphere(t_obj_list **objects, char **line);
int		parse_plane(t_obj_list **objects, char **line);
int		parse_cylinder(t_obj_list **objects, char **line);
int		add_to_list(t_object *new_object, t_obj_list **objects);
int		is_normed_v(t_vector *vec);

//helper functions
// free
void	print_error(char *error_msg);
void	free_object_list(t_obj_list *objects);
void	ft_free_tab(char ***tab);
void	free_scene(t_scene *scene);

// strings
double	ft_atod(const char *str);

//DEBUGGING
// print scene
void	print_scene(t_scene *scene);
void	print_object(t_object *obj);

#endif
