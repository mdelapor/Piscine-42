/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stroggen <stroggen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:05:42 by stroggen          #+#    #+#             */
/*   Updated: 2026/09/27 18:18:33 by stroggen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_parsing
{
	char	*file;
	int		fd;
}	t_parsing;

typedef struct s_dict
{
	char	*number_word;
	char	*number_index;
}	t_dict;

int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup(char *str);
int		main(int argc, char **argv);
void	print_string(char *str);
void	print_string_space(char *str);
int		tab_size(char **tab);
int		ft_strlen(char *str);
int		check_arguments(int argc, char **argv, char *nb, t_parsing *parsing);
int		check_number(char *file, char *nb);
void	read_doc(t_parsing *parsing, char *nb);
char	**ft_split(char *str, char *charset);

#endif
