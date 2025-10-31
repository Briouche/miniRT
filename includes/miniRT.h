/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 21:11:50 by brcoppie         ###   ########.fr       */
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
	int	sp_count;
	int	pl_count;
	int	cy_count;
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
	t_object	object;
	t_obj_list	*next;
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
int		parsing(int ac, char **av);


//helper functions

//is
int		ft_isalpha(int a);
int		ft_isuppercase(int a);
int		ft_isdigit(int a);

//strings
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(const char *str, char c);
long	ft_atol(const char *str);
double	ft_atod(const char *str);

//get_next_line
char	*ft_gnl(int fd);

#endif