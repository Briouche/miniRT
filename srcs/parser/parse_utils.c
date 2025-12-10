/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:16:12 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/10 13:31:45 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	parse_color(const char *str, t_vector *colors)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (1);
	if (!tokens[0] || !tokens[1] || !tokens [2] || tokens[3])
	{
		ft_free_array((void **)tokens);
		return ((input_error("colors need to have three \
values between [0,255]\n", NULL)));
	}
	colors->x = ft_atoi(tokens[0]);
	colors->y = ft_atoi(tokens[1]);
	colors->z = ft_atoi(tokens[2]);
	colors->w = 0;
	ft_free_array((void **)tokens);
	if (colors->x < 0 || colors->x > 255 \
		|| colors->y < 0 || colors->y > 255 \
		||colors->z < 0 || colors->z > 255)
		return (input_error("colors need to have three \
values between [0,255]\n", NULL));
	return (0);
}

int	parse_point(const char *str, t_vector *p)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (1);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3])
	{
		ft_free_array((void **)tokens);
		return (input_error("points need three coordinates\n", NULL));
	}
	p->x = ft_atod(tokens[0]);
	p->y = ft_atod(tokens[1]);
	p->z = ft_atod(tokens[2]);
	p->w = 1;
	ft_free_array((void **)tokens);
	if (isinf(p->x) || isinf(p->y) || isinf(p->z))
		return (input_error("coordinates need to be double values\n", NULL));
	return (0);
}

int	parse_vector(const char *str, t_vector *v)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3]
		|| !tokens[0][0] || !tokens[1][0] || !tokens[2][0])
	{
		ft_free_array((void **)tokens);
		return (input_error("vectors need three coordinates\n", NULL));
	}
	v->x = ft_atod(tokens[0]);
	v->y = ft_atod(tokens[1]);
	v->z = ft_atod(tokens[2]);
	v->w = 0;
	ft_free_array((void **)tokens);
	if (isinf(v->x) || isinf(v->y) || isinf(v->z))
		return (input_error("components need to be double values\n", NULL));
	return (0);
}
