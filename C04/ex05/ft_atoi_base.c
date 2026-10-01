/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelapor <mdelapor@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 13:49:32 by mdelapor          #+#    #+#             */
/*   Updated: 2026/10/01 14:15:58 by mdelapor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		base_len;

	i = 0;
	num = 0;
	sign = 1;
	base_len = ft_strlen(base);
	if (check_base(base, base_len) == 0)
		return (0);
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = convert_num(str, base, base_len, i);
	return (sign * num);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	argc = argc;
	printf("str : %s\nbase : %s\nresult : %i\n", argv[1], argv[2],
	ft_atoi_base(argv[1], argv[2]));
}*/
