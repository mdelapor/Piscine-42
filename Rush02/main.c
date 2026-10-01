/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stroggen <stroggen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:06:22 by stroggen          #+#    #+#             */
/*   Updated: 2026/09/27 18:08:47 by stroggen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	struct s_parsing	*parsing;
	char				*nb;

	parsing = malloc(sizeof(struct s_parsing) * 1);
	nb = ft_strdup(argv[1]);
	if (check_arguments(argc, argv, nb, parsing) == -1)
		return (-1);
	read_doc(parsing, nb);
	if (parsing->fd != -1)
		close(parsing->fd);
	free(parsing->file);
	free(parsing);
}
