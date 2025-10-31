/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:27:07 by brcoppie          #+#    #+#             */
/*   Updated: 2025/10/31 11:52:58 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static void	*ft_free(char **tab, size_t w)
{
	size_t	i;

	i = 0;
	while (i < w)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	*make_word(char *str, char c)
{
	size_t	i;
	char	*word;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	w;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			tab[w++] = make_word((char *) &s[i], c);
		if (w > 0 && !tab[w - 1])
			return (ft_free(tab, w));
		while (s[i] != c && s[i])
			i++;
	}
	tab[w] = 0;
	return (tab);
}
/*
int	main(void)
{
	char	s[] = "hehe salut, tu marche?";
	char	**tab;
	size_t	i;

	tab = ft_split(s, ' ');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
*/