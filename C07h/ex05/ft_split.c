/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmallia <qmallia@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:31:25 by qmallia           #+#    #+#             */
/*   Updated: 2026/09/24 14:02:31 by qmallia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_charset(charset, str[i + 1]) && !is_charset(charset, str[i]))
			count++;
		i++;
	}
	return (count);
}

void	assign_letters(char *str, char *charset, char *word)
{
	int	i;

	i = 0;
	while (!is_charset(charset, str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
}

int	assign_words(char *str, char *charset, char **res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (is_charset(charset, str[i]))
			i++;
		else
		{
			k = i;
			while (!is_charset(charset, str[k]))
				k++;
			res[j] = malloc(sizeof(char) * (k - i + 1));
			assign_letters(&str[i], charset, res[j]);
			j++;
			i = k;
		}
	}
	return (j);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words_count;
	int		last;

	words_count = ft_count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * words_count + 1);
	last = assign_words(str, charset, res);
	res[last] = NULL;
	return (res);
}
/*#include <stdio.h>
int	main(int argc, char **argv)
{
	char	**res;
	int		i;

	i = 0;
	(void)argc;
	res = ft_split(argv[1], argv[2]);
	printf("STR : \"%s\"\nCHARSET : \"%s\"\n\n", argv[1], argv[2]);
	//printf("{ \"%s\" \"%s\" \"%s\" }", res[0], res[1], res[2]);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}
*/
