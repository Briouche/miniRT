/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:29:48 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/25 17:35:06 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*join;

	if (argc != 3)
		return (1);
	join = ft_strjoin(argv[1], argv[2]);
	printf("%s + %s = %s\n", argv[1], argv[2], join);
	free(join);
	return (0);
}