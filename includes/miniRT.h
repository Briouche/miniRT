/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/25 18:03:51 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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


//parsing
int		parsing(int ac, char **av);

//get_next_line
char	*ft_gnl(int fd);

#endif