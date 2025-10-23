/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:25:49 by brcoppie          #+#    #+#             */
/*   Updated: 2025/10/23 19:33:29 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	find_newline(char *s)
{
	int	i;

	if (!s || s == NULL)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	fill_leftovers(char **leftovers, char *buffer)
{
	char	*temp;

	if (!(*leftovers))
		*leftovers = ft_strdup(buffer);
	else
	{
		temp = ft_strdup(*leftovers);
		free(*leftovers);
		*leftovers = NULL;
		if (!temp)
			return ;
		*leftovers = ft_strjoin(temp, buffer);
		if (!(*leftovers))
			*leftovers = NULL;
		free(temp);
	}
}

char	*copy_until_nl(char *str, int index)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(index + 2);
	if (!res)
		return (NULL);
	while (i <= index)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*split_on_nl(char **leftovers)
{
	int		i;
	char	*result;
	char	*temp;
	char	*old;

	if (!*leftovers)
		return (NULL);
	i = find_newline(*leftovers);
	if (i == -1)
	{
		result = ft_strdup(*leftovers);
		free(*leftovers);
		*leftovers = NULL;
		if (!result)
			result = NULL;
		return (result);
	}
	result = copy_until_nl(*leftovers, i);
	old = *leftovers;
	temp = &((*leftovers)[i + 1]);
	*leftovers = ft_strdup(temp);
	free(old);
	return (result);
}

char	*ft_gnl(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*leftovers;
	char		*str;
	int			bytes_read;

	while (find_newline(leftovers) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		fill_leftovers(&leftovers, buffer);
	}
	str = split_on_nl(&leftovers);
	return (str);
}
