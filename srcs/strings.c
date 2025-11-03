/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:15:29 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/03 15:43:48 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*str;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = (char) s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = (char) s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cpy;

	cpy = malloc(ft_strlen((char *) s1) * sizeof(const char) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
