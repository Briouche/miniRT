/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:34 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/03 15:48:42 by fkrakow          ###   ########.fr       */
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
	if (parsing(ac, av[1]))
		return (1);
	//print_file(av[1]);
	//open_window();
	return (0);
}
