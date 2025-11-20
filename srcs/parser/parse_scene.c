/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:52:56 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/20 18:17:15 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static char	**parse_line(int fd)
{
	char	*line;
	char	**tokens;

	line = ft_gnl(fd);
	if (!line)
		return (NULL);
	tokens = ft_split(line, ' ');
	free(line);
	if (tokens == NULL)
		ft_putstr_fd("Error while spliting the input.\n", 2);
	return (tokens);
}

int	input_error(const char *msg, t_object *obj)
{
	ft_putstr_fd("Invalid input: ", 2);
	ft_putstr_fd(msg, 2);
	if (obj)
		free(obj);
	return (1);
}

static int	parse_tokens(t_scene *scene, char *const tokens[])
{
	if (!ft_strcmp(tokens[0], "sp"))
		return (parse_sphere(&scene->objs_list, &scene->size, tokens));
	else if (!ft_strcmp(tokens[0], "pl"))
		return (parse_plane(&scene->objs_list, &scene->size, tokens));
	else if (!ft_strcmp(tokens[0], "cy"))
		return (parse_cylinder(&scene->objs_list, &scene->size, tokens));
	else if (!ft_strcmp(tokens[0], "A"))
		return (parse_ambient(scene, tokens));
	else if (!ft_strcmp(tokens[0], "C"))
		return (parse_camera(scene, tokens));
	else if (!ft_strcmp(tokens[0], "L"))
		return (parse_light(scene, tokens));
	else if (tokens[0] != NULL)
		return (input_error("unkown element\n", NULL));
	return (0);
}

int	parse_scene(t_scene *scene, const char *filename)
{
	int			fd;
	char		**tokens;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	tokens = parse_line(fd);
	while (tokens)
	{
		if (tokens[0] && tokens[0][0] != '\n' && parse_tokens(scene, tokens))
		{
			ft_putstr_fd("Error while parsing tokens\n", 2);
			ft_free_array((void **)tokens);
			close(fd);
			return (1);
		}
		ft_free_array((void **)tokens);
		tokens = parse_line(fd);
	}
	close(fd);
	return (0);
}
