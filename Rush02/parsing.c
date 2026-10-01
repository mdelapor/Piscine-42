/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stroggen <stroggen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:52:38 by stroggen          #+#    #+#             */
/*   Updated: 2026/09/27 18:08:27 by stroggen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_number(char *file, char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
		{
			print_string("Error.\nInvalid Number.\n");
			if (file != NULL)
				free(file);
			free(nb);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	file_name_check(t_parsing *parsing, char *nb)
{
	print_string("Error.\nWrong file name.\n");
	free(parsing->file);
	free(nb);
	free(parsing);
	return (-1);
}

int	check_arguments(int argc, char **argv, char *nb, t_parsing *parsing)
{
	if (argc < 2 || argc > 3)
	{
		print_string("Error.\nInvalid Numbers of arguments.\n");
		free(parsing);
		return (-1);
	}
	if (argc == 2)
	{
		nb = ft_strdup(argv[1]);
		parsing->file = ft_strdup("numbers.dict");
	}
	else if (argc == 3)
	{
		nb = ft_strdup(argv[2]);
		parsing->file = ft_strdup(argv[1]);
	}
	parsing->fd = open(parsing->file, O_RDONLY);
	if (parsing->fd == -1)
		return (file_name_check(parsing, nb));
	return (check_number(parsing->file, nb));
}
