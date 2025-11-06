/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannon_ball.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:02:16 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/06 13:46:00 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdio.h>

typedef struct s_projectile
{
	t_vector	position;
	t_vector	velocity;
}	t_proj;

typedef struct s_environnement
{
	t_vector	gravity;
	t_vector	wind;
}	t_envir;

t_proj	tick(t_proj *projectile, t_envir *environnement)
{
	t_proj		next_pos;
	t_vector	tmp;

	next_pos.position = op_plus(&projectile->position, &projectile->velocity);
	tmp = op_plus(&environnement->gravity, &environnement->wind);
	next_pos.velocity = op_plus(&projectile->velocity, &tmp);
	return (next_pos);
}

int	cannon_ball(t_display *img, t_vector *color)
{
	t_proj		projectile;
	t_envir		environnement;
	double		tmp;
	t_vector	tmp_vec;

	projectile.position = (t_vector){0, 1, 0, 1};
	projectile.velocity = (t_vector){1, 1.8, 0, 0};
	tmp = 11.25;
	tmp_vec = op_normalise(&projectile.velocity);
	projectile.velocity = op_multi(&tmp_vec, &tmp);
	environnement.gravity = (t_vector){0, -0.1, 0, 0};
	environnement.wind = (t_vector){-0.01, 0, 0, 0};
	while (projectile.position.y >= 0)
	{
		put_pixel_to_image(img, projectile.position.x,
			HEIGHT - projectile.position.y, color);
		projectile = tick(&projectile, &environnement);
	}
	return (0);
}
