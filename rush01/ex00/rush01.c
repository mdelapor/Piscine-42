/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preynaud <preynaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 17:38:55 by preynaud          #+#    #+#             */
/*   Updated: 2026/09/20 17:50:21 by preynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	nb_input(char *str, int *clues)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (i <= 16)
	{
		if (str[i] < '1' || str[i] > '4')
			ft_putstr("Error");
		if (i < 15 && str[i + 1] != ' ')
			ft_putstr("Error");
		clues[i] = str[i] - '0';
		i += 2;
	}
	return (str[31] == '\0');
}

int	count_box(int *start, int step)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i <= 4)
	{
		if (start[step * i] > max)
		{
			max = start[i * step];
			count++;
		}
		i++;
	}
	return (count);
}
