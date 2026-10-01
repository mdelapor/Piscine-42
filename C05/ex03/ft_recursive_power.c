/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelapor <mdelapor@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:18:45 by mdelapor          #+#    #+#             */
/*   Updated: 2026/09/27 17:43:51 by mdelapor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 0)
		return (i * ft_recursive_power(nb, power - 1));
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_recursive_power(27, 1));
}*/
