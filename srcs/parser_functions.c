/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:44:39 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/06 14:25:17 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	parse_point(char *str, t_vector *p)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3] || \
		!tokens[0][0] || !tokens[1][0] || !tokens[2][0])
		return (ft_free_tab(&tokens), 0);
	p->x = ft_atod(tokens[0]);
	p->y = ft_atod(tokens[1]);
	p->z = ft_atod(tokens[2]);
	if (p->x == -DBL_MAX || p->y == -DBL_MAX || p->z == -DBL_MAX)
		return (ft_free_tab(&tokens), 0);
	ft_free_tab(&tokens);
	return (1);
}

int	parse_vector(char *str, t_vector *v)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3] || \
		!tokens[0][0] || !tokens[1][0] || !tokens[2][0])
		return (ft_free_tab(&tokens), 0);
	v->x = ft_atod(tokens[0]);
	v->y = ft_atod(tokens[1]);
	v->z = ft_atod(tokens[2]);
	if (v->x == -DBL_MAX || v->y == -DBL_MAX || v->z == -DBL_MAX)
		return (ft_free_tab(&tokens), 0);
	ft_free_tab(&tokens);
	return (1);
}

int	parse_color(char *str, t_vector *colors)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3] || \
		!tokens[0][0] || !tokens[1][0] || !tokens[2][0])
		return (ft_free_tab(&tokens), 0);
	colors->x = ft_atoi(tokens[0]);
	colors->y = ft_atoi(tokens[1]);
	colors->z = ft_atoi(tokens[2]);
	ft_free_tab(&tokens);
	if (colors->x < 0 || colors->x > 255 \
		|| colors->y < 0 || colors->y > 255 \
		||colors->z < 0 || colors->z > 255)
		return (0);
	return (1);
}

//!!!also check if magnitude == 1!!! sqrt(x² + y² + z²)
int	is_normed_v(t_vector *vec)
{
	if (vec->x > 1 || vec->x < -1 || vec->y > 1 || \
		vec->y < -1 || vec->z > 1 || vec->z < -1)
		return (0);
	else
		return (1);
}

int	parse_camera(t_scene **scene, char **line)
{
	if ((*scene)->count.camera_count > 0)
		return (print_error("More than 1 Camera\n"), 0);
	(*scene)->count.camera_count++;
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (print_error("Bad Camera line\n"), 0);
	if (line[0][0] != 'C' || line[0][1])
		return (print_error("Bad Camera line\n"), 0);
	if (!parse_point(line[1], &(*scene)->cam.viewpoint))
		return (print_error("Bad Camera viewpoint\n"), 0);
	if (!parse_vector(line[2], &(*scene)->cam.orientation)
		|| !is_normed_v(&(*scene)->cam.orientation))
		return (print_error("Bad Camera orientation\n"), 0);
	(*scene)->cam.fov = ft_atod(line[3]);
	if ((*scene)->cam.fov > 180 || (*scene)->cam.fov < 0)
		return (print_error("Bad Camera FOV\n"), 0);
	return (1);
}
