/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:09:02 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 17:18:31 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "../vectors/vectors.h"

//shading

typedef struct s_light_info
{
	float	reflect_dot_eye;
	float	light_dot_normal;
	t_vector	effective_color;
	t_vector	final_color;
	t_vector	lightv;
	t_vector	eyev;
}	t_light_info;

typedef struct s_material
{
	t_vector	color;
	float		ambient;
	float		diffuse;
	float		specular;
	float		shininess;
}	t_material;

// objects' definition
typedef struct s_sphere
{
	double		r;
	t_vector	c;
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
	double		radius;
	double		height;
	t_vector	c;
	t_vector	v;
	t_vector	color;
}	t_cylinder;

// objects' types
typedef enum e_type
{
	NONE,
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
	t_matrix	tr_matrix;
	t_matrix	inv_tr;
	t_material	mat;
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
	double		ratio;
	t_vector	coord;
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
