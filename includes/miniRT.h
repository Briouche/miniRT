/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 16:32:25 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <float.h>

# define BUFFER_SIZE 64


//base structs
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}			t_point;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}			t_vec;

typedef struct s_colors
{
	int	R;
	int	G;
	int	B;
}		t_colors;


//object structs

typedef struct s_count
{
	int	ambient_count;
	int	camera_count;
	int	light_count;
	int	obj_count;
}	t_count;


typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_sphere
{
	t_point		center;
	double		diameter;
	t_colors	color;
}			t_sphere;

typedef struct s_plane
{
	t_point		p;
	t_vec		v;
	t_colors	color;
}				t_plane;

typedef struct s_cylinder
{
	t_point		center;
	t_vec		v;
	double		diameter;
	double		height;
	t_colors	color;
}	t_cylinder;

typedef struct s_object
{
	t_type	type;
	union u_obj
	{
		t_sphere	sp;
		t_plane		pl;
		t_cylinder	cy;
	}				obj;
}	t_object;

typedef struct s_obj_list
{
	t_object			*object;
	struct s_obj_list	*next;
}	t_obj_list;


//other elements
typedef struct s_ambient
{
	double		ratio;
	t_colors	color;
}	t_ambient;

typedef struct s_camera
{
	t_point	viewpoint;
	t_vec	orientation;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_point		coord;
	double		ratio;
	t_colors	color;
}	t_light;


//scene
typedef struct s_scene
{
	t_ambient	ambient_light;
	t_camera	cam;
	t_light		light;
	t_object	*objects;
	t_count		count;
}	t_scene;



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