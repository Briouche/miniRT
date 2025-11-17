/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:34 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/17 15:06:14 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char *const argv[])
{
	t_display	display;
	t_scene		scene;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Usage: minirt <scene.rt>\n", 2);
		return (1);
	}
	if (parsing(argv[1], &scene))
		return (1);
	print_scene(&scene);
	if (init_display(&display))
		return (1);
	if (render_image(&display))
		return (1);
	display_loop(&display);
	return (0);
}
