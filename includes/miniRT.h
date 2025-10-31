/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:06 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 12:48:53 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../vectors/vectors.h"
# include "display.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define WIDTH 512
# define HEIGHT 512

// main functions
int		init_display(t_display *display);
int		render_image(t_display *img);
void	display_loop(t_display *display);

//parsing
int		parsing(int ac, char **av);


#endif