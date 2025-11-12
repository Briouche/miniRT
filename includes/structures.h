/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:09:02 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/12 15:28:59 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "../vectors/vectors.h"

// objects' definition
typedef struct s_sphere
{
	t_vector	c;
	double		r;
	t_vector	color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	p;
	t_vector	v;
	t_vector	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	c;
	t_vector	v;
	double		diameter;
	double		height;
	t_vector	color;
}	t_cylinder;

// objects' types
typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

// objects themselves
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

// list of all objects
typedef struct s_obj_list
{
	t_object			*object;
	struct s_obj_list	*next;
}	t_obj_list;

//scene's elements
typedef struct s_ambient
{
	double		ratio;
	t_vector	color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	viewpoint;
	t_vector	orientation;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	coord;
	double		ratio;
	t_vector	color;
}	t_light;

// to limit our number of ambient light,
// camera, and light to one
typedef struct s_count
{
	int	ambient_count;
	int	camera_count;
	int	light_count;
}	t_count;

// the scene itself containing all the information
// from the input file
typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	cam;
	t_light		light;
	t_object	*objects;
	t_obj_list	*objs_list;
	int			size;
	t_count		count;
}	t_scene;

#endif
