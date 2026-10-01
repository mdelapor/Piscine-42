/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmallia <qmallia@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 22:46:54 by qmallia           #+#    #+#             */
/*   Updated: 2026/09/27 00:43:37 by qmallia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		number_len_new_base(int nb, int base_len);
void	ft_encrypt_nbr(int nbr, char *final_nbr, char *base_to, int final_len);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == '\f'
			|| base[i] == '\n' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\r' || base[i] == ' ')
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

long	convert_num(char *str, char *base, int base_len, int i)
{
	int	num;
	int	j;

	num = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != base[j] && base[j])
			j++;
		if (!base[j])
			return (num);
		num = num * base_len + j;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = convert_num(str, base, ft_strlen(base), i);
	return (sign * num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		final_len;
	char	*final_nbr;

	if (!check_base(base_from) || !check_base(base_to))
		return ((void *) 0);
	nb = ft_atoi_base(nbr, base_from);
	final_len = number_len_new_base(nb, ft_strlen(base_to));
	final_nbr = malloc(sizeof(char) * final_len);
	ft_encrypt_nbr(nb, final_nbr, base_to, (final_len - 2));
	return (final_nbr);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("nbr: %s\nbase_from: %s\nbase_to: %s\nresult: %s\n",
	argv[1], argv[2], argv[3], ft_convert_base(argv[1], argv[2], argv[3]));
}*/
