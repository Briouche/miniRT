/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannon_ball.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:02:16 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 12:57:28 by fkrakow          ###   ########.fr       */
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

int	cannon_ball(void)
{
	proj	projectile;
	envir	environnement;	

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
	return (0);
}