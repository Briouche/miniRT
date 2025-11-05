/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:34 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 18:17:19 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

//void	print_file(char *filename)
//{
//    int		fd;
//    char	*line;

//	fd = open(filename, O_RDONLY);
//	if (fd < 0)
//	{
//		perror("open");
//		return;
//	}
//	line = ft_gnl(fd);
//	while (line != NULL)
//	{
//		ft_putstr_fd(line, 1);
//		free(line);
//		line = ft_gnl(fd);
//	}
//	ft_putchar_fd('\n', 1);
//	close(fd);
//}

int	main(int ac, char **av)
{
	t_display	display;
	t_scene		*scene;

	//parsing tester
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (print_error("Malloc failed\n"), 1);
	if (parsing(ac, av[1], &scene))
		return (1);
	//print_file(av[1]);
	print_scene(scene);
	free_scene(&scene);


	printf("=========================================================\n");
	printf("|=============== Chapter 1: CANNON BALL ================|\n");
	(void)ac;
	(void)av;
	if (init_display(&display))
		return (1);
	if (render_image(&display))
		return (1);
	display_loop(&display);
	return (0);
}
