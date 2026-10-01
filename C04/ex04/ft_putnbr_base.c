/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmallia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:07:30 by qmallia           #+#    #+#             */
/*   Updated: 2026/09/21 12:05:19 by qmallia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base_len <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	l_nbr;

	l_nbr = nbr;
	base_len = ft_strlen(base);
	if (check_base(base, base_len) == 0)
		return ;
	if (l_nbr < 0)
	{
		ft_putchar('-');
		l_nbr *= -1;
	}
	if (l_nbr >= base_len)
	{
		ft_putnbr_base((l_nbr / base_len), base);
		ft_putchar(base[(l_nbr % base_len)]);
	}
	else
		ft_putchar(base[l_nbr]);
}
