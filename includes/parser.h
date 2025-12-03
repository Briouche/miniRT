/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:40:02 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 16:53:54 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structures.h"
# include <fcntl.h>
# include <stdio.h>

int		check_filename(const char *filename);
int		check_openread(const char *filename);

// parsing
int		parse_file(const char *filename, t_scene *scene);
int		parse_scene(t_scene *scene, const char *filename);
int		input_error(const char *msg, t_object *obj);
int		add_to_list(t_object *new_obj, t_obj_list **obj_list);

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

void	precompute_transforms(t_object *obj_arr, t_scene *scene);

//DEBUGGING
void	print_scene(t_scene *scene);

#endif
