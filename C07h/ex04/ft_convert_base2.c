/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmallia <qmallia@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 23:34:06 by qmallia           #+#    #+#             */
/*   Updated: 2026/09/26 18:31:37 by qmallia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

void	ft_encrypt_nbr(int nbr, char *nb, char *base_to, int len)
{
	int		i;
	int		base_len;
	long	l_nbr;

	i = 0;
	l_nbr = nbr;
	base_len = ft_strlen(base_to);
	if (l_nbr < 0)
	{
		nb[0] = '-';
		l_nbr *= -1;
	}
	while (l_nbr >= base_len)
	{
		nb[len - i] = base_to[l_nbr % base_len];
		l_nbr /= base_len;
		i++;
	}
	nb[len - i] = base_to[l_nbr];
}

int	number_len_new_base(int nb, int base_len)
{
	int	size;

	size = 2;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb >= base_len)
	{
		nb /= base_len;
		size++;
	}
	return (size);
}
