/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:31:45 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/08 11:25:16 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	char	*dst;
	int		i;

	dst = malloc((n + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < n && *src)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
