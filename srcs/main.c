/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:34 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 17:31:47 by brcoppie         ###   ########.fr       */
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

int	cannon_ball(void);

// void	open_window(void)
// {
// 	void	*mlx_ptr;
// 	void	*mlx_win;

// 	mlx_ptr = mlx_init();
// 	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "miniRT");
// 	(void)mlx_win;
// 	mlx_loop(mlx_ptr);
// }

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
	cannon_ball();
	if (init_display(&display))
		return (1);
	if (render_image(&display))
		return (1);
	display_loop(&display);
	return (0);
}
