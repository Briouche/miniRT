/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:34 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 15:13:24 by fkrakow          ###   ########.fr       */
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

	(void)ac;
	(void)av;
	if (init_display(&display))
		return (1);
	if (render_image(&display))
		return (1);
	display_loop(&display);
	return (0);
}
