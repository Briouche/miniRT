/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:56:58 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/05 16:37:31 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_error(char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
}

void	free_scene(t_scene **scene)
{
	if (!scene || !(*scene))
		return ;
	if ((*scene)->objects)
	{
		free((*scene)->objects);
		(*scene)->objects = NULL;
	}
	free(*scene);
	*scene = NULL;
}

void	ft_free_tab(char ***tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	free_object_list(t_obj_list *objects)
{
	t_obj_list	*tmp;

	while (objects)
	{
		tmp = objects->next;
		free(objects->object);
		free(objects);
		objects = tmp;
	}
}
