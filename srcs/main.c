/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:34 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 17:07:05 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char *const argv[])
{
	t_display	display;
	t_scene		scene;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Usage: miniRT <scene.rt>\n", 2);
		return (1);
	}
	if (parsing(argv[1], &scene))
		return (1);
	if (init_display(&display))
	{
		free(scene.objects);
		return (1);
	}
	if (render_image(&display, &scene))
	{
		free(scene.objects);
		return (1);
	}
	free(scene.objects);
	display_loop(&display);
	return (0);
}
