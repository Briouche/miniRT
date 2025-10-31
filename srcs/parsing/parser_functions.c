/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:44:39 by brcoppie          #+#    #+#             */
/*   Updated: 2025/10/31 21:24:53 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	parse_point(char *str, t_point *p)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3])
		return (ft_free_tab(tokens), 0);
	p.x = ft_atod(tokens[0]);
	p.y = ft_atod(tokens[1]);
	p.z = ft_atod(tokens[2]);
	if (p.x == -DBL_MAX || p.y == -DBL_MAX || p.z == -DBL_MAX)
		return (ft_free_tab(tokens), 0);
	ft_free_tab(tokens);
	return (1);
}

int	parse_vector(char *str, t_vec *v)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3])
		return (ft_free_tab(tokens), 0);
	v.x = ft_atod(tokens[0]);
	v.y = ft_atod(tokens[1]);
	v.z = ft_atod(tokens[2]);
	if (v.x == -DBL_MAX || v.y == -DBL_MAX || v.z == -DBL_MAX)
		return (ft_free_tab(tokens), 0);
	ft_free_tab(tokens);
	return (1);
}

int	parse_camera(t_scene **scene, char **line)
{
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (0);
	if (line[0][0] != 'C' || line[0][1])
		return (0);
	if (!parse_point(line[1], &(*scene)->cam.viewpoint))
		return (0);
	if (!parse_vector(line[2], &(*scene)->cam.orientation))
		return (0);
	if (((*scene)->cam.orientation.x > 1.0 || (*scene)->cam.orientation.x < -1.0) \
		|| ((*scene)->cam.orientation.y > 1.0 || (*scene)->cam.orientation.y < -1.0) \
		|| ((*scene)->cam.orientation.z > 1.0 || (*scene)->cam.orientation.z < -1.0))
		return (0);
	(*scene)->cam.fov = ft_atod(line[3]);
	if ((*scene)->cam.fov > 180 || (*scene)->cam.fov < 0)
		return (0);
	return (1);
}
