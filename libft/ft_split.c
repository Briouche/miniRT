/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:27:07 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/08 11:24:53 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_words(const char *str, char c)
{
	size_t	count;

	while (*str == c)
		str++;
	if (!*str)
		return (0);
	count = 1;
	while (*str++)
		count += *str == c && *(str + 1) && *(str + 1) != c;
	return (count);
}

static int	copy_split_word(char **split, const char *s, int len)
{
	*split = ft_strndup(s, len);
	if (!*split)
		return (1);
	return (0);
}

static int	fill_split(char **split, const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == c)
		{
			if (len && copy_split_word(split++, s, len))
				return (1);
			s += len + 1;
			len = 0;
		}
		else
			len++;
	}
	if (len && copy_split_word(split, s, len))
		return (1);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((1 + get_num_words(s, c)), sizeof(char *));
	if (!split)
		return (NULL);
	if (fill_split(split, s, c))
	{
		ft_free_array((void **)split);
		return (NULL);
	}
	return (split);
}
