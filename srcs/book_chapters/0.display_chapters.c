/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.display_chapters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:46:52 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/01 14:06:22 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	display_book_chapter(t_display *img, t_scene *scene)
{
	int	chapter;

	chapter = 1;
	if (chapter == 3)
		cannon_ball(img, &(t_vector){0, 255, 0, 0});
	else if (chapter == 4)
		draw_clock(img, &(t_vector){255, 0, 0, 0});
	else if (chapter == 5)
		sphere_silhouette(scene, img);
	return (0);
}
