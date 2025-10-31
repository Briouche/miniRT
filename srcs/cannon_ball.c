/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannon_ball.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:02:16 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 15:20:41 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdio.h>

typedef struct projectile
{
	t_vector	position;
	t_vector	velocity;
} proj;

typedef struct environnement
{
	t_vector	gravity;
	t_vector	wind;
} envir;

proj	tick(proj *projectile, envir *environnement)
{
	proj		next_pos;
	t_vector	tmp;

	next_pos.position = op_plus(&projectile->position, &projectile->velocity);
	tmp = op_plus(&environnement->gravity, &environnement->wind);
	next_pos.velocity = op_plus(&projectile->velocity, &tmp);
	return (next_pos);
}

int	cannon_ball(t_display *img, t_vector *color)
{
	proj		projectile;
	envir		environnement;

	projectile.position = (t_vector){0, 1, 0, 1};
	projectile.velocity = (t_vector){1, 1, 0, 0};
	environnement.gravity = (t_vector){0, -0.1, 0, 0};
	environnement.wind = (t_vector){-0.01, 0, 0, 0};

	while (projectile.position.y >= 0)
	{
		printf("|---                                                 ---|\n");
		printf("|\tposition: (%f, %f, %f)\t|\n", projectile.position.x, projectile.position.y, projectile.position.z);
		projectile = tick(&projectile, &environnement);
	}	
	printf("---------------------------------------------------------\n");
	
	projectile.position = (t_vector){0, 1, 0, 1};
	projectile.velocity = (t_vector){1, 1.8, 0, 0};
	double		tmp = 11.25;
	t_vector	tmp_vec = op_normalise(&projectile.velocity);
	projectile.velocity = op_multi(&tmp_vec, &tmp);
	environnement.gravity = (t_vector){0, -0.1, 0, 0};
	environnement.wind = (t_vector){-0.01, 0, 0, 0};
	while (projectile.position.y >= 0)
	{
		put_pixel_to_image(img, projectile.position.x ,HEIGHT -  projectile.position.y, color);
		projectile = tick(&projectile, &environnement);
	}	
	return (0);
}