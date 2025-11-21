/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:09:02 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/21 12:58:29 by brcoppie         ###   ########.fr       */
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
	double		radius;
	double		height;
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
