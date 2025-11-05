/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:12:05 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/05 16:17:54 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

char	**tokenize_line(int fd)
{
	char	*line;
	char	**tokens;
	char	*newline;

	line = ft_gnl(fd);
	if (!line)
		return (NULL);
	if ((newline = ft_strchr(line, '\n')))
		*newline = '\0';
	tokens = ft_split(line, ' ');
	free(line);
	return (tokens);
}

int	parse_line(t_scene **scene, t_obj_list **objects, char **tokens)
{
	if (!tokens || !tokens[0] || !tokens[0][0])
		return (0);
	else if (tokens[0][0] == 'C' && !tokens[0][1])
		return (parse_camera(scene, tokens));
	else if (tokens[0][0] == 'A' && !tokens[0][1])
		return (parse_ambient(scene, tokens));
	else if (tokens[0][0] == 'L' && !tokens[0][1])
		return (parse_light(scene, tokens));
	else if (tokens[0][0] == 's' && tokens[0][1] == 'p')
		return (parse_sphere(objects, tokens));
	else if (tokens[0][0] == 'c' && tokens[0][1] == 'y')
		return (parse_cylinder(objects, tokens));
	else if (tokens[0][0] == 'p' && tokens[0][1] == 'l')
		return (parse_plane(objects, tokens));
	return (1);
}
