/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelapor <mdelapor@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:57:17 by mdelapor          #+#    #+#             */
/*   Updated: 2026/09/26 16:13:15 by mdelapor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 0)
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	return (nb);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_recursive_factorial(4));
}*/
