/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:12:05 by brcoppie          #+#    #+#             */
/*   Updated: 2025/10/31 21:35:29 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

char	**tokenize_line(int fd)
{
	char	*line;
	char	**tokens;

	line = ft_gnl(fd); //malloc 2
	if (!line)
		return (NULL);
	tokens = ft_split(line, ' ');
	free(line); //free 2
	return (tokens);
}

int	parse_line(t_scene **scene, t_obj_list **objects, char **tokens)
{
	if (!tokens || !tokens[0])
		return (0);
	else if (tokens[0][0] == 'C' && !tokens[0][1])
		parse_camera(scene, tokens);
	else if (tokens[0][0] == 'A' && !tokens[0][1])
		parse_ambient(scene, tokens);
	else if (tokens[0][0] == 'L' && !tokens[0][1])
		parse_light(scene, tokens);
	else if (tokens[0][0] && tokens[0][1])
		parse_objects(scene, objects, tokens);
	return (1);
}
