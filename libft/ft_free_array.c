/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:16:05 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/08 11:13:54 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void **arr)
{
	int	n;

	if (!arr)
		return ;
	n = -1;
	while (arr[++n])
		free(arr[n]);
	free(arr);
}
