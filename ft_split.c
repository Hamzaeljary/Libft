/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:34:44 by heljary           #+#    #+#             */
/*   Updated: 2024/10/29 09:34:47 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			words++;
			i += ft_wordlen(&s[i], c);
		}
	}
	return (words);
}

static void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_fill_words(char **strs, const char *s, char c)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			word_len = ft_wordlen(&s[i], c);
			strs[j] = ft_substr(s, i, word_len);
			if (!strs[j])
				return (0);
			i += word_len;
			j++;
		}
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (!s || s[0] == '\0')
	{
		strs = (char **)malloc(sizeof(char *));
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	words = ft_count_words(s, c);
	strs = malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	if (!ft_fill_words(strs, s, c))
	{
		ft_free_split(strs);
		return (NULL);
	}
	return (strs);
}
