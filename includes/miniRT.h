/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 17:00:25 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../vectors/vectors.h"
# include "display.h"
# include "structures.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include <mlx.h>
#include <float.h>

# define WIDTH 512
# define HEIGHT 512

# define BUFFER_SIZE 64



// main functions
int		init_display(t_display *display);
int		render_image(t_display *img);
void	display_loop(t_display *display);

//parsing
int		check_filename(char *filename);
int		check_openread(char *filename);
int		list_to_array(t_scene *scene, t_obj_list *objects);
int		parse_scene(t_scene **scene, char *filename);
int		parsing(int ac, char *filename, t_scene **scene);
char	**tokenize_line(int fd);
int		parse_line(t_scene **scene, t_obj_list **objects, char **tokens);
int		parse_point(char *str, t_point *p);
int		parse_vector(char *str, t_vec *v);
int		parse_color(char *str, t_colors *colors);
int		parse_camera(t_scene **scene, char **line);
int		parse_ambient(t_scene **scene, char **line);
int		parse_light(t_scene **scene, char **line);
int		parse_sphere(t_obj_list **objects, char **line);
int		parse_plane(t_obj_list **objects, char **line);
int		parse_cylinder(t_obj_list **objects, char **line);
int		add_to_list(t_object *new_object, t_obj_list **objects);
int		is_normed_v(t_vec *vec);


//helper functions
// free
void	print_error(char *error_msg);
void	free_object_list(t_obj_list *objects);
void	ft_free_tab(char ***tab);
void	free_scene(t_scene **scene);

// is
int		ft_isalpha(int a);
int		ft_isuppercase(int a);
int		ft_isdigit(int a);

// strings
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(const char *str, char c);
long	ft_atol(const char *str);
double	ft_atod(const char *str);
int		ft_atoi(const char *str);

// get_next_line
char	*ft_gnl(int fd);

//DEBUGGING
// print scene
void	print_scene(t_scene *scene);
void	print_object(t_object *obj);
void	print_vector(t_vec v);
void	print_point(t_point p);
void	print_color(t_colors color);

#endif
