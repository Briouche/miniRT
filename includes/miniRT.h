/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/23 21:39:17 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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


//helper functions

//strings
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

//get_next_line
char	*ft_gnl(int fd);

#endif