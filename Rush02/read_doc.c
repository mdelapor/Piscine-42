/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stroggen <stroggen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:57:38 by stroggen          #+#    #+#             */
/*   Updated: 2026/09/27 18:13:46 by stroggen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

void	set_struct_dict(t_dict *dict, char **tab)
{
	char	**tab_tmp;
	int		i;

	i = 0;
	while (tab[i])
	{
		tab_tmp = ft_split(tab[i], " :");
		dict[i].number_word = ft_strdup(tab_tmp[1]);
		dict[i].number_index = ft_strdup(tab_tmp[0]);
		free(tab_tmp[0]);
		free(tab_tmp[1]);
		free(tab_tmp[2]);
		i++;
	}
	dict[i].number_word = NULL;
	dict[i].number_index = NULL;
}

void	hundred_dict_hundred(t_dict *dict, char *nb)
{
	int	i;

	i = 0;
	while (dict[i].number_index)
	{
		if (ft_strncmp(nb, dict[i].number_index, 0) == 0 && i < 10)
			print_string_space(dict[i].number_word);
		if (ft_strncmp("100", dict[i].number_index, 3) == 0)
			print_string_space(dict[i].number_word);
		i++;
	}
}

void	hundred_dict(t_dict *dict, char *nb)
{
	int	i;
	int	comp;

	i = 0;
	if (nb[1] == '1')
		comp = 2;
	else
		comp = 0;
	hundred_dict_hundred(dict, nb);
	i = 0;
	while (dict[i].number_index)
	{
		if (ft_strncmp(nb + 1, dict[i].number_index, comp) == 0 && i > 10)
			print_string_space(dict[i].number_word);
		i++;
	}
	i = 0;
	while (dict[i].number_index && comp != 2)
	{
		if (ft_strncmp(nb + 2, dict[i].number_index, 1) == 0
			&& i < 10 && nb[2] != '0')
			print_string(dict[i].number_word);
		i++;
	}
}

void	read_doc(t_parsing *parsing, char *nb)
{
	char			tmp[900];
	char			**tab;
	struct s_dict	*dict;
	int				i;

	read(parsing->fd, tmp, 900);
	tab = ft_split(tmp, "\n");
	dict = malloc(sizeof(struct s_dict) * tab_size(tab));
	set_struct_dict(dict, tab);
	i = 0;
	if (ft_strlen(nb) == 3)
		hundred_dict(dict, nb);
}
