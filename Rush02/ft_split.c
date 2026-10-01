/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stroggen <stroggen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:46:46 by stroggen          #+#    #+#             */
/*   Updated: 2026/09/27 18:04:59 by stroggen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	**is_string(char *str, char *charset, char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) && is_sep(str[i + 1], charset))
			i++;
		else if (is_sep(str[i], charset) && is_sep(str[i + 1]
				, charset) == 0 && str[i + 1])
		{
			count++;
			i++;
		}
		else
			i++;
	}
	tab = malloc(sizeof(char *) * (count + 2));
	if (!tab)
		return (NULL);
	return (tab);
}

char	*ft_strdup_words(char *str, int beg, int end)
{
	char	*word;
	int		i;
	int		index;

	i = 0;
	index = beg;
	word = malloc(sizeof(char) * (end - beg + 1));
	if (!word)
		return (NULL);
	while (index < end)
	{
		word[i] = str[index];
		i++;
		index++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		indextab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = NULL;
	indextab = 0;
	tab = is_string(str, charset, tab);
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		j = i;
		if (!str[i])
			break ;
		while (str[i] && !(is_sep(str[i], charset)))
			i++;
		tab[indextab] = ft_strdup_words(str, j, i);
		indextab++;
	}
	tab[indextab] = NULL;
	return (tab);
}
